#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Contessa: public Player
    {
    private:
        /* data */
    public:
        Contessa(Game const &g1,string const &name);
        ~Contessa();
        void block(Player const &p);
    };
    
    
}