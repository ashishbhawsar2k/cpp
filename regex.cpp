#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int example_1()
{
    // Simple regular expression matching
    std::string fnames[] = {"foo.txt", "bar.txt", "baz.dat", "zoidberg"};
    std::regex txt_regex("[a-z]+\\.txt");
 
    for (const auto &fname : fnames) {
        std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
    }   
 
    // Extraction of a sub-match
    std::regex base_regex("([a-z]+)\\.txt");
    std::smatch base_match;
 
    for (const auto &fname : fnames) {
        if (std::regex_match(fname, base_match, base_regex)) {
            // The first sub_match is the whole string; the next
            // sub_match is the first parenthesized expression.
            if (base_match.size() == 2) {
                std::ssub_match base_sub_match = base_match[1];
                std::string base = base_sub_match.str();
                std::cout << fname << " has a base of " << base << '\n';
            }
        }
    }
 
    // Extraction of several sub-matches
    std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
    std::smatch pieces_match;
 
    for (const auto &fname : fnames) {
        if (std::regex_match(fname, pieces_match, pieces_regex)) {
            std::cout << fname << '\n';
            for (size_t i = 0; i < pieces_match.size(); ++i) {
                std::ssub_match sub_match = pieces_match[i];
                std::string piece = sub_match.str();
                std::cout << "  submatch " << i << ": " << piece << '\n';
            }   
        }   
    }   

    return 0;
}

void example_2()
{
	std::ifstream in("us_postal.txt");
	// input file
	if (!in) cerr << "no file\n";
	
	//std::regex pat {R"(\w{2}\s∗\d{5}(−\d{4})?)"};
	std::regex pat {R"([A-D]+)"};
	// U.S. postal code pattern
	int lineno = 0;	
	for (string line; getline(in,line);) {
		cout <<"Reading file line:" << line << endl;
		++lineno;
		std::smatch matches; // matched strings go here
		if (std::regex_search(line , matches, pat)) {
		    cout << lineno << ": " << matches[0] << '\n'; // the complete match
		    if (1<matches.size() && matches[1].matched)
			cout << "\t: " << matches[1] << '\n'; // submatch
		}
	}
}

void example_3(){
    //const char *reg_exp = "[ ,.\\t\\n;:]";  // List of separator characters.
    const char *reg_exp = R"([- ,.\t\n;:])";
    std::regex rgx(reg_exp); // 'regex' is an instance of the template class
			    // 'basic_regex' with argument of type 'char'.
    std::cmatch match; // 'cmatch' is an instance of the template class
		      // 'match_results' with argument of type 'const char *'.
    const char *target = ";Unseen University - Ankh-Morpork	";
    std::cout <<"Going to apply Regex\n";
    // Identifies all words of 'target' separated by characters of 'reg_exp'.
    if (std::regex_search(target, match, rgx)) {
	// If words separated by specified characters are present.

	std::cout << "Total Matches : " << match.size() << '\n'; // the complete match
/*	for (const_iterator b = match.begin(); b != match.end(); b+++
	  std::cout << "Matched element:" << b << std::endl;
*/
	const size_t n = match.size();
	for (size_t a = 0; a < n; a++) {
	    cout << "Matched:[" << match[a] << "]"<< endl;
	    std::string str (match[a].first, match[a].second);
	    std::cout << str << "\n";
	}
    }
    else{
	std::cout << " Failed to apply Regex\n";
    }
 
}

int main(int argc, char **argv)
{
	//example_1();
	//example_2();
	example_3();
	
	return 0;
}
