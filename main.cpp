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
    triD kropka;
    kropka.cordZ=0;
    int sizz, legn;
    short wpisana;
    std::cout << "First. Choose the length of your road: ";
    std::cin >> legn;
    std::cout << "\n Good.\nNow - ammount of lanes on your road: ";
    std::cin >> sizz;
    std::cout << "\nTwo more things - which lane do you want to focus on: ";
    std::cin >> wpisana;
    std::cout << "\nThank god, thats all - a car can occupy one lane, choose which lane: ";
    std::cin >> kropka.cordX;
    bool game=true;

    while(game){
        std::cout << "\033[2J\033[1;1H";
        drawer(sizz, legn, kropka.cordX, kropka.cordZ, wpisana);
        usleep(500000);
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
