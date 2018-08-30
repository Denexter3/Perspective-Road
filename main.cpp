#include <iostream>
#include <unistd.h>

class triD
{
public:
    int cordX;
    int cordY;
    int cordZ;
};

void drawer(int X, int Z, int OX, int OZ, short wpis);

int main()
{
    int sizz, legn;
    short wpisana;
    triD kropka;
    bool game=true;
    kropka.cordZ=1;

    while(game){
        std::cout << "\033[2J\033[1;1H";
        drawer(sizz, legn, kropka.cordX, kropka.cordZ, wpisana);
        usleep(1000000);
        kropka.cordZ+=1;
    }
    return 0;
}

void drawer(int X, int Z, int OX, int OZ, short wpis)
{
    short dzmien=(-wpis)+1;
    short pzmien=(-dzmien-2)*Z+dzmien;
    int przyblizenie=0;
    int oddalenie;
    oddalenie=Z*2+pzmien;
    for(int bZ=1; bZ<=Z; bZ++){
        przyblizenie+=1;
        oddalenie=oddalenie+dzmien;
        std::cout << "\n";
        bool wykonane=false;
        int h=1;
        for(int bX=1; bX<=X; bX++){
            if(wykonane==false)
                {
                    for(int b=1; b<=oddalenie; b++)
                    {
                        std::cout << " ";
                    }
                }
            wykonane=true;
            if((OX==bX) && (OZ==bZ)) std::cout << "0";
            else std::cout << ".";
            if(h<=X-1)
                {
                    for(int g=1; g<przyblizenie; g++) std::cout << " ";
                }
            h++;
        }
    }
}
