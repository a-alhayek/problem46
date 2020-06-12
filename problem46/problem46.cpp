#include "problem46.hpp"
std::set<int> findallprimes(){
    std::set<int> primeSet;
    primeSet.insert(2);
    for (int i =3 ; i < 1000000 ; i++){
        bool found  =false;
        for (std::set<int>::iterator it=primeSet.begin(); it!=primeSet.end(); ++it){
            if (i% *it ==0) {
                found = true;
                break;

            }
            if (*it * *it > i){
                break;
            }

        }
        if (!found)
            primeSet.insert(i);
    }
    return primeSet;
}


int smallestOddComposite(){ // problem 46 in project euler

    std::set<int> primeNumbers = findallprimes();


    for (int i =9 ; i < 10000 ; i+=2){
        auto it = primeNumbers.find(i);
        if  ( it!= primeNumbers.end()) {
            continue;
        }

        if(!goldbachTheory(i,  primeNumbers)){
            return i;
        }


    }
    return 0;
}

bool goldbachTheory(int num ,  std::set<int> primeNumbers){


    for (auto it = primeNumbers.begin() ; it != primeNumbers.end() ; ++it)

    {
        if (*it >= num ){
            break;
        }
        for(int i = 1 ; i <= sqrt(num) ; i++)
        {
            if (*it + 2* pow(i, 2) == num)
            {
                return true;
            }

        }



    }
    return false;


}
