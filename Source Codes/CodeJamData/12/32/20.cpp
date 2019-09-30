#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <bitset>

using namespace std;

// typedef
typedef __int64 int64;
typedef unsigned __int64 uint64;
typedef unsigned int uint;

// define
#ifdef _DEBUG
#	define CHECK_DATA 1
#else
#	define CHECK_DATA 0
#endif

#ifdef    WIN32
#	define DIRECTORY_SEPARATOR '\\'
#else
#	define DIRECTORY_SEPARATOR '/'
#endif

#define DEFAULT_INPUT "test.txt"
#define DEFAULT_OUTPUT "result.txt"
#define DEFAULT_ANSWER "answer.txt"

//=========================================================================//
//     Problem Class
//=========================================================================//
class Problem{
private:
	// input
	int N, A;
	double D;
	vector<pair<double, double>> TX;
	vector<double> a;
	// tmp
	// result
	vector<double> result;
public:
	//--------------------------------------------------------------------//
	//     Get Input
	//--------------------------------------------------------------------//
	void GetInput(istream& in){
		in >> D >> N >> A;
		for(int i=0; i<N; ++i){
			double t, x;
			in >> t >> x;
			TX.push_back(make_pair(t, x));
		}
		for(int i=0; i<A; ++i){
			double t;
			in >> t;
			a.push_back(t);
		}
	}
	//--------------------------------------------------------------------//
	//     Output for Debug
	//--------------------------------------------------------------------//
	void DebugOutput(ostream& out) const{

	}
	//--------------------------------------------------------------------//
	//     Solve
	//--------------------------------------------------------------------//
	/*
		double dt = TX[j].first - TX[j-1].first;
		double dp = (D - TX[j-1].second) / (TX[j].second - TX[j-1].second);
		double r = dt * dp + TX[j-1].first;
		result[i] = max(r, result[i]);
	*/

	void Solve(){
		result.resize(A, -1);
		for(uint i=0; i<a.size(); ++i){
			// D = 0.5 * a[i] * t * t;
			// result[i] = sqrt(D / (0.5 * a[i]));

			double v = 0, p = 0, t = 0;
			for(uint j=0; j<TX.size(); ++j){
				double target = min(D, TX[j].second);
				// target = v * t + 0.5 * a[i] * t * t;
				double ax = 0.5 * a[i], bx = v, cx = -(target-p);
				double my_time = t + (-bx + sqrt(bx*bx - 4 * ax * cx)) / (2 * ax);
				// other
				double other_time = 0;
				if(j > 0){
					double dt = TX[j].first - TX[j-1].first;
					double dp = (target - TX[j-1].second) / (TX[j].second - TX[j-1].second);
					other_time = dt * dp + TX[j-1].first;
				}
				if(my_time >= other_time){
					if(target == D){
						result[i] = my_time;
						break;
					}
					// ?
				}
				else{
					if(target == D){
						result[i] = other_time;
						break;
					}
					else{
						p = target;
						v += a[i] * (my_time - t);
						t = other_time;
					}
				}
			}
		}
	}

	//--------------------------------------------------------------------//
	//     Output Result
	//--------------------------------------------------------------------//
	void OutputResult(ostream& out) const{
		out << endl;
		for(uint i=0; i<result.size(); ++i){
			out << setprecision(20) << result[i] << endl;
		}
	}
};

//=========================================================================//
//     Open Files
//=========================================================================//
int OpenFiles(const int argc, const char *argv[], ifstream *in_file, fstream *out_file){
	string input_file_name = (argc > 1)? argv[1]: DEFAULT_INPUT;
	uint index = input_file_name.find_last_of(DIRECTORY_SEPARATOR);
	string dir = (index+1 < input_file_name.size())? input_file_name.substr(0, index+1): "",
		        output_file_name = dir + DEFAULT_OUTPUT;

	in_file->open(input_file_name.c_str());
	if(!in_file->is_open()){
		cout << "Input File Open Error: [" << input_file_name << "]" << endl;
		return -1;
	}

	out_file->open(output_file_name.c_str(), ios::in | ios::out | ios::trunc);
	if(!out_file->is_open()){
		cout << "Output File Open Error: [" << output_file_name << "]" << endl;
		return -1;
	}

	return 0;
}

int OpenFiles(const int argc, const char *argv[], ifstream *result_file, ifstream *answer_file){
	string input_file_name = (argc > 1)? argv[1]: DEFAULT_INPUT;
	uint index = input_file_name.find_last_of(DIRECTORY_SEPARATOR);
	string dir = (index+1 < input_file_name.size())? input_file_name.substr(0, index+1): "",
		        output_file_name = dir + DEFAULT_OUTPUT;
	string answer_file_name = (argc > 1)? argv[2]: DEFAULT_ANSWER;

	result_file->open(output_file_name.c_str());
	if(!result_file->is_open()){
		cout << "Result File Open Error: [" << input_file_name << "]" << endl;
		return -1;
	}

	answer_file->open(answer_file_name.c_str());
	if(!answer_file->is_open()){
		//cout << "Result File Open Error: [" << input_file_name << "]" << endl;
		//return -1;
	}

	return 0;
}

//=========================================================================//
//     Compare Result
//=========================================================================//
void CompareResult(ifstream *result, ifstream *answer){
	if(!answer->is_open()){
		return;
	}

	string line1, line2;
	uint count = 0;
	bool ok = true;
	while(!result->eof() || !answer->eof()){
		++count;

		if(result->eof() && !answer->eof()){
			cout << "Answerには" << count << "行目がありません。" << endl;
			ok = false;
			break;
		}
		else if(!result->eof() && answer->eof()){
			cout << "Resultには" << count << "行目がありません。" << endl;
			ok = false;
			break;
		}

		getline(*result, line1);
		getline(*answer, line2);

		if(line1 != line2){
			cout << count << "行目が異なります。" << endl
				<< "	" << line1 << endl
				<< "	" << line2 << endl;
			ok = false;
		}
	}

	if(ok){
		cout << "Correct" << endl;
	}
	else{
		cout << "InCorrect" << endl;
	}
}

//=========================================================================//
//     Get All Stream Content
//=========================================================================//
template<typename Stream>
void GetAll(string *buf, Stream *stream){
	char c;
	while(!stream->eof()){
		*stream >> c;
		*buf += c;
	}
}

//=========================================================================//
//     Main
//=========================================================================//
int main(const int argc, const char *argv[]){
	// Get File Name
	ifstream in_file;
	fstream out_file;
	if(OpenFiles(argc, argv, &in_file, &out_file) != 0){
		return -1;
	}

	// Get Start Time
	clock_t start, end;
	start = clock();

	// Get number of problems
	uint number_of_problems;
	in_file >> number_of_problems;
	getline(in_file, string());
	
	cout << "=====[Result]===============" << endl;
	Problem problem;
	for(uint i=0; i<number_of_problems; ++i){
		problem = Problem();
		// Get Input
		problem.GetInput(in_file);
		// Solve
		problem.Solve();
		// Output
		out_file << "Case #" << (i+1) << ":";
		cout << "Case #" << (i+1) << ":";
		problem.OutputResult(cout);
		problem.OutputResult(out_file);
#if CHECK_DATA
		problem.DebugOutput(cout);
#endif
	}

	// Get End Time
	end = clock();

	// File Close
	in_file.close();
	out_file.close();

	// Result Open
	ifstream result_file, answer_file;
	OpenFiles(argc, argv, &result_file, &answer_file);

	cout << endl;
	cout << "=====[Info]=================" << endl;
	cout << "time: "
	     << setprecision(2) << setiosflags(ios::fixed)
	     << (end - start) << "sec" << endl;
	CompareResult(&result_file, &answer_file);
	cout << endl;

	

	return 0;
}