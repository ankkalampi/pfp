#include "bit_array.hpp"
#include "packed_array.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>







    constexpr uint64_t defaultN = 100;
    constexpr uint64_t defaultM = 100;
    constexpr uint64_t  defaultR = 1337;
    constexpr bool defaultS = false;
    constexpr bool defaultA = false;
    constexpr bool defaultB = true;
    constexpr bool defaultC = false;


    int main(int argc, char const* argv[] ){
        uint64_t n = defaultN;
        uint64_t m = defaultM;
        uint64_t r = defaultR;
        bool sFlag = defaultS;
        bool aFlag = defaultA;
        bool bFlag = defaultB;
        bool cFlag = defaultC;
        bool abcSet = false;
        bool dataFileExists = false;
        std::string dataFile;



        for (int i = 1; i < argc; ++i){
            std::string s(argv[i]);
            if ( s == "-n"){
                try{
                    n = std::stoull(argv[++i]);
                } catch (const std::invalid_argument&){
                    std::cerr << "invalid number argument!" << std::endl;
                    return -1;
                }
                
            } else if (s == "-m"){
                try{
                    m = std::stoull(argv[++i]);
                } catch (const std::invalid_argument&){
                    std::cerr << "invalid number argument!" << std::endl;
                    return -1;
                }
            } else if (s == "-r"){
                try{
                    r = std::stoull(argv[++i]);
                } catch (const std::invalid_argument&){
                    std::cerr << "invalid number argument!" << std::endl;
                    return -1;
                }
            } else if (s == "-a"){
                if (abcSet) {
                    std::cerr << "mode argument invalid! Provide only one of a, b, or c." << std::endl;
                    return -1;
                }
                aFlag = true;
                bFlag = false;
                cFlag = false;
            } else if (s == "-b"){
                if (abcSet) {
                    std::cerr << "mode argument invalid! Provide only one of a, b, or c." << std::endl;
                    return -1;
                }
                aFlag = false;
                bFlag = true;
                cFlag = false;
            } else if (s == "-c"){
                if (abcSet) {
                    std::cerr << "mode argument invalid! Provide only one of a, b, or c." << std::endl;
                    return -1;
                }
                aFlag = false;
                bFlag = false;
                cFlag = true;
            } else{
                if (s[0] == '-'){
                    std::cerr << "unknown argument!" << std::endl;
                    return -1;
                }

                if (dataFileExists){
                    std::cerr << "only one data file allowed!" << std::endl;
                    return -1;
                }

                dataFile = std::string(argv[i]);
                dataFileExists = true;
            }
        }

        return 0;
    }
