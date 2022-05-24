
#include <fstream>
#include <iostream>
#include <vector>

#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main(int argc, char** argv)
{

    // First, just grab the input data from request.json
    json request;    
    std::ifstream requestStream("./request.json");
    requestStream >> request;

    // Now determine all the prime factors
    vector<ulong> factors;
    factors.push_back(1);
    ulong originalN = request.at("N");
    ulong currentN = originalN;
    ulong currentFactor = 2;

    // Loop through all the possible factors.
    while (currentFactor <= currentN)
    {

        // Add the factor if it divides the currentN
        if (currentN % currentFactor == 0)
        {

            factors.push_back(currentFactor);
            currentN /= currentFactor;

        }

        // If the current factor is large enough, we can just add the last factor
        else if (currentFactor > pow(currentN, 0.5))
        {
            factors.push_back(currentN);
            currentN = 1;
        }

        // Otherwise, just increment the currentFactor
        else
            currentFactor += 1;

    }

    // Keep track of square sums
    vector<vector<ulong>> sums;

    // Now try and find a solution for the "Sum of two squares" problem
    for (ulong x = 1; pow(x, 2) <= originalN; x++)
    {
        ulong xPower = pow(x, 2);
        for (ulong y = x; pow(y, 2) + xPower <= originalN; y++)
        {
            if (xPower + pow(y, 2) == originalN)
            {
                vector<ulong> solution;
                solution.push_back(x);
                solution.push_back(y);
                sums.push_back(solution);
            }
        }
    }

    // Write to output
    json response;
    response["factors"] = factors;
    response["squareSums"] = sums;

    std::ofstream responseStream("response.json");
    responseStream << response;


}