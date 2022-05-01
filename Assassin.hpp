#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Assassin : public Player
    {
    private:
        /* data */
    public:
        Assassin(Game const &g1,string const &name);
        ~Assassin();
        void Elimante(Player const &to);
        
    };
    
    
}