#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include "linear.h"

using namespace std;

int main(int argc, char ** argv) {
    linear_regression lin;

    vector<float> x = { 10, 34, 14, 56, 8 };
    vector<float> y = { 98, 46, 3,  75, 27 };

    cout << "Linear      [ ";
    lin.linear(x, y);
    cout << " ]\n";

    cout << "Exponential [ ";
    lin.exponential(x, y);
    cout << " ]\n";

    cout << "Polynomial  [ ";
    lin.polynomial(x, y, 3); //degrees
    cout << " ]\n";

    return 0;
}

