

#include <cstdint>
#include <cstdlib>
#include <vector>

namespace pfp{

    class BitArray{
        private:
        uint64_t* bitarray;
        const int limit;

        public:
        BitArray(const int limit) : limit(limit){
            bitarray = (uint64_t*)std::calloc(limit / 64 + 1, sizeof(uint64_t));
            
        }

        ~BitArray(){
            free(bitarray);
        }

        void set(int i){
            int mod = i % limit;
            bitarray[ limit / 64] |= (1ULL << mod);
        }

        int get(int i){
            int mod = i % limit;
            return (bitarray[limit / 64] >> mod) & 1;

        }

    };
}