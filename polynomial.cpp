#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class Polynomial {
    public:
    int *degCoeff;
    int size;
    Polynomial(){
        degCoeff = new int[5];
        for(int i = 0;i<5;i++){
            degCoeff[i]=0;
        }
        size = 5;
    }
    Polynomial(Polynomial const &p2){
        degCoeff = new int[p2.size];
        for(int i = 0;i<p2.size;i++){
            degCoeff[i]=p2.degCoeff[i];
        }
        size = p2.size;
    }
    void operator=(Polynomial const &p2){
        this -> degCoeff = new int[p2.size];
        for(int i = 0;i<p2.size;i++){
            this -> degCoeff[i]=p2.degCoeff[i];
        }
        this -> size = p2.size;
    }
    void setCoefficient(int degree, int coeff){
        if(degree >= size){
            int *newdegCoeff = new int[degree +1];
            for(int i= 0;i<size;i++){
                newdegCoeff[i]=degCoeff[i];
            }
            for(int i = size;i<degree+1;i++){
                newdegCoeff[i]=0;
            }
            delete [] degCoeff;
            degCoeff = newdegCoeff;
            size = degree+1;
        }
        degCoeff[degree]= coeff;
    }
    void print(){
        for(int i = 0;i<size;i++){
            if(this -> degCoeff[i]!=0){
                cout<<this -> degCoeff[i]<<"x"<<i<<" ";
            }
        }cout<<endl;
    }
    Polynomial operator+(Polynomial const &p2){
        Polynomial result;
        result.size = max(size,p2.size);
        result.degCoeff = new int[result.size];
        if(size<p2.size){
            int i = 0;
            for(;i<size;i++){
                result.degCoeff[i]=degCoeff[i]+p2.degCoeff[i];
            }
            for(;i<p2.size;i++){
                result.degCoeff[i]=p2.degCoeff[i];
            }
        }
        else{
            int i= 0;
            for(;i<p2.size;i++){
                result.degCoeff[i]=degCoeff[i]+p2.degCoeff[i];
            }
            for(;i<size;i++){
                result.degCoeff[i]=degCoeff[i];
            }
        }
        return result;
    }
    Polynomial operator-(Polynomial const &p2){
        Polynomial result;
        result.size = max(size,p2.size);
        result.degCoeff = new int[result.size];
        if(size<p2.size){
            int i = 0;
            for(;i<size;i++){
                result.degCoeff[i]=degCoeff[i]-p2.degCoeff[i];
            }
            for(;i<p2.size;i++){
                result.degCoeff[i]=-p2.degCoeff[i];
            }
        }
        else{
            int i= 0;
            for(;i<p2.size;i++){
                result.degCoeff[i]=degCoeff[i]-p2.degCoeff[i];
            }
            for(;i<size;i++){
                result.degCoeff[i]=degCoeff[i];
            }
        }
        return result;
    }
    Polynomial operator*(Polynomial const &p2){
        Polynomial result;
        result.size = size + p2.size;
        result.degCoeff = new int[result.size];
        for(int i = 0;i<result.size;i++){
            result.degCoeff[i]=0;
        }
        for(int i = 0;i<size;i++){
            for(int j = 0;j<p2.size;j++){
                result.degCoeff[j+i]+=degCoeff[i]*p2.degCoeff[j];
            }
        }
        return result;
    }
};

int main() {
    int count1, count2, choice;
    cin >> count1;

    int * degree1 = new int[count1];
    int * coeff1 = new int[count1];

    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int * degree2 = new int[count2];
    int * coeff2 = new int[count2];

    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice) {
        // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2:
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3:
            result = first * second;
            result.print();
            break;

        case 4: // Copy constructor
        {
            Polynomial third(first);
            if (third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            } else {
                cout << "true" << endl;
            }
            break;
        }

        case 5: // Copy assignment operator
        {
            Polynomial fourth(first);
            if (fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            } else {
                cout << "true" << endl;
            }
            break;
        }

    }

    return 0;
}