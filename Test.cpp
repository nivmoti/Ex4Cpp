#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace coup;

#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
TEST_CASE("not enough coins"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    CHECK_THROWS(duke.coup(assassin));
    CHECK_THROWS(assassin.Elimante(duke));
    CHECK_THROWS(ambassador.coup(assassin));
    CHECK_THROWS(captain.coup(contessa));
}
TEST_CASE("Skip turn"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
    duke.income();
    CHECK_THROWS(ambassador.income());

}
TEST_CASE("Cannot be blocked"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
    Captain captainse{game_1, "tut"};
	Contessa contessa{game_1, "Gilad"};
    duke.tax();
    assassin.income();
    CHECK_THROWS(contessa.block(assassin));
    ambassador.income();
    captain.income();
    CHECK_THROWS(captainse.block(captain));
    captainse.income();
    CHECK_THROWS(ambassador.block(captainse));
    contessa.income();
    CHECK_THROWS(duke.block(contessa));  
}
TEST_CASE("Check Game system"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    for (int i = 0; i < 5; i++)
    {
        duke.foreign_aid();
        assassin.foreign_aid();
        ambassador.foreign_aid();
        captain.foreign_aid();
        contessa.foreign_aid();
    }
    CHECK_THROWS(game_1.winner());
    CHECK_THROWS(duke.tax());
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.transfer(contessa,duke));
    CHECK_THROWS(captain.steal(duke));
    CHECK_THROWS(contessa.foreign_aid());
    Game game_2{};
    Duke du{game_2, "Moshe"};
    CHECK_THROWS(du.income());//limit of player is between 2-6.
    Game game_3{};
    Duke duk{game_3, "Moshe"};
	Assassin assassi{game_3, "Yossi"};
	Ambassador ambassado{game_3, "Meirav"};
	Captain captai{game_3, "Reut"};
	Contessa contess{game_3, "Gilad"};
    Duke duk_2{game_3, "Mose"};
     Duke duk_3{game_3, "Mos"};
     CHECK_THROWS(duk.income());   
}
TEST_CASE("Good Game"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    duke.tax();
    int s=duke.coins();
    CHECK(s==3);
    assassin.foreign_aid();
    duke.block(assassin);
    CHECK(assassin.coins()==0);
    CHECK_EQ(game_1.turn(),"Meirav");
    ambassador.transfer(duke,assassin);
    CHECK_EQ(duke.coins(),2);
    CHECK(assassin.coins()==1);
    captain.steal(duke);
    CHECK_EQ(captain.coins(),1);
    contessa.income();
    for (int i = 0; i < 9; i++)
    {
        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
    }
    duke.coup(ambassador);
    assassin.Elimante(captain);
    contessa.block(assassin);
    CHECK(game_1.turn()=="Reut");
    captain.coup(duke);
    contessa.coup(captain);
    vector<string> names={"Yossi","Gilad"};
    CHECK(game_1.players()==names);
    assassin.coup(contessa);
    CHECK(game_1.winner()=="Yossi");

    


    
}

