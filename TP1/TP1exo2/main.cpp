#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int nbvoyelles(std::string const &mot)
{
    int nbvoy(0);
    for(int i=0; i<mot.size();++i)
    {
        if(mot[i]=='a' || mot[i]=='e' || mot[i]=='i' || mot[i]=='o' || mot[i]=='u' || mot[i]=='y' )
            ++nbvoy;
    }
    return nbvoy;
}

bool palindrome(std::string const &mot)
{
    int i(0);
    int taille = mot.size();

    while(i<(taille/2))
    {
        if(mot[i] != mot[(taille-1)-i])
            return false;
        ++i;
    }

    return true;
}


std::string chiffrer(std::string const &mot, int decalage)
{
    std::string chaine=mot;

    for(int i=0; i<mot.size();++i)
    {

        if(mot[i]<'z'+1 && mot[i]>'a'-1)
        {
            if(mot[i]+decalage<'z'+1)
                chaine[i] = mot[i]+decalage;
            else
                chaine[i] = (mot[i]+decalage)-26;
        }
        else if(mot[i]<'Z'+1 && mot[i]>'A'-1)
        {
            if(mot[i]+decalage<'Z'+1)
                chaine[i] = mot[i]+decalage;
            else
                chaine[i] = (mot[i]+decalage)-26;
        }

    }
    return chaine;
}


unsigned int convertCharToInt(char const & c) {

    return(c-48);
}

unsigned int convertStringToInt(std::string const & chaine) {

    if(chaine.size()==0)
        return 0;
    else if(chaine.size()==1)
    {
            return convertCharToInt(chaine[chaine.size()-1]);
    }
    else{
            return (convertCharToInt(chaine[chaine.size()-1])+10*convertStringToInt(chaine.substr(0,chaine.size()-1)));
    }
}



int main()
{
    std::string s;
    std::cin >> s;
    std::cout<< nbvoyelles(s)<<std::endl;

    if(palindrome(s))
         std::cout<< "palindrome"<<std::endl;
    else
         std::cout<< "pas palindrome"<<std::endl;

    std::cout<<chiffrer(s,5)<<std::endl;


    for(int b=0;b<10;++b)
    {
        std::cout<<"      CONVERT STRING TO INT    "<<std::endl;

        std::string s2;
        std::cin>>s2;
        std::cout<<"string :   "<<s2<<std::endl;
        int i = convertStringToInt(s2);
        std::cout<<"int    :   "<<i<<std::endl;
    }



    return 0;
}

//abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
