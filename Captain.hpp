#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Captain : public Player
    {
    private:
        /* data */
    public:
        Captain(Game const &g1,string const &name);
        ~Captain();
        void steal(Player const &from);
    };
    
}