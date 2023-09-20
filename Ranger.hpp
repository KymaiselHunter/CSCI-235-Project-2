#ifndef RANGER_HPP
#define RANGER_HPP

#include "Character.hpp"

#include<string>
#include<vector>

struct Arrows
{
    std::string type_;
    int quantity_;
};


class Ranger: public Character
{
    private:
        std::vector<Arrows> arrows_;
        std::vector<std::string> affinities_;
        bool has_companion;

    public:
        Ranger();
        //Ranger();

};



#endif //RANGER_HPP