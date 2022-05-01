#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Ambassador : public Player
    {
    private:
        /* data */
    public:
        Ambassador(Game const &g1,string const &name);
        ~Ambassador();
        static void transfer(Player const &from,Player const &to);
        
    };
    
    
}