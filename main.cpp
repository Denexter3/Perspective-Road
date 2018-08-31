#include <iostream>
#include <unistd.h> // Only for usleep, nothing else

class triD  // Class for the "car" thingy
{
public:
    int cordX;
    int cordY; // At first this program wasgoing to support all X Y Z coordinates. Now it supports only X and Z
    int cordZ;
};

void drawer(int X, int Z, int OX, int OZ, short wpis);

int main()
{
    triD kropka;
    kropka.cordZ=0;
    int sizz, legn;
    short wpisana;
    std::cout << "Example numbers for fullscreen terminal:\nLength - 10\nAmmount - 6\n";
    std::cout << "Lane to focus - close to Ammount, can be less than it\nLane for a car - not higher than ammount and higher than zero\n";
    std::cout << "First. Choose the length of your road: ";
    std::cin >> legn;
    std::cout << "\n Good.\nNow - ammount of lanes on your road: ";
    std::cin >> sizz;
    std::cout << "\nTwo more things - which lane do you want to focus on: ";
    std::cin >> wpisana;
    std::cout << "\nThank god, thats all - a car can occupy one lane, choose which lane: ";
    std::cin >> kropka.cordX;
    bool game=true;

    while(game){ // Game is true as long as you dont add something that will change that
        std::cout << "\033[2J\033[1;1H";
        drawer(sizz, legn, kropka.cordX, kropka.cordZ, wpisana);
        usleep(500000); //One frame is on the screen for half a second
        kropka.cordZ+=1;
        if (kropka.cordZ>legn) kropka.cordZ=0;
    }
    return 0;
}

void drawer(int X, int Z, int OX, int OZ, short wpis)
{
    short dzmien=(-wpis);  // This one controls which lane you focus on
    short pzmien=(-dzmien-2)*Z+dzmien; // This controls the shift of the road on the X axis
    int przyblizenie=0;
    int oddalenie;
    oddalenie=Z*2+pzmien;
    for(int bZ=1; bZ<=Z; bZ++){  // The "Z" dimension
        przyblizenie+=1;
        oddalenie=oddalenie+dzmien;
        std::cout << "\n";
        bool wykonane=false;
        int h=1;
        for(int bX=0; bX<=X+1; bX++){ // The "X" dimension with one additional phantom lane
            if(bZ==1) continue; // The first line of the road is not drawn
            if(wykonane==false)
                {
                    for(int b=1; b<=oddalenie; b++)
                    {
                        std::cout << " ";
                    }
                }
            wykonane=true;
            if((OX==bX) && (OZ==bZ)) std::cout << "0";
            else if(bX==0 || bX==X+1) std::cout << "B"; // Draws borders on two "phantom" lanes on the road
            else std::cout << ".";
            if(h<=X+1) // +1 adds last phantom lane the perspecitive making process
                {
                    for(int g=1; g<przyblizenie; g++) std::cout << " ";
                }
            h++;
        }
    }
}
