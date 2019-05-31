#include "noerror.h"
#include <string>
using namespace std;
namespace noe {
    int maxOverlap (string prefix, string suffix) {
        for(int i=0; i<suffix.length(); i++) {
            if(suffix[i]!=prefix[i]) return -1;
        }
        return suffix.length();
    }
}

