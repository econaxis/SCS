#ifndef LCS_Scorer
#define LCS_Scorer
#include <string>

namespace LCS{
double maxf(double a, double b);
double lcs_compute(std::string X, std::string Y);
std::vector<std::vector<double>> init2 (std::string pref, std::string suff, std::pair<double, int> &bestAns);
}
#endif
