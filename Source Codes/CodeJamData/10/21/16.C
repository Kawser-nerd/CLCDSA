#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool ParentDirExist(string aStr, vector<string>& vStr){
  bool bret=false;
  for(int i=0; i<vStr.size(); i++){
    if(vStr.at(i)==aStr) bret=true;
  }
  return bret;
};

int main() {
  int T, N, M;
  cin >> T;
  for(int iT=0; iT<T; iT++) {
    cin >> N >> M;
    string nStr;
    string mStr;
    vector<string> vnStr;
    vector<string> vmStr;
    vnStr.push_back("/");
    for(int iN=0; iN<N; iN++){
      cin >> nStr;
      nStr+="/";
      vnStr.push_back(nStr);
    }
    for(int iM=0; iM<M; iM++) {
      cin >> mStr;
      string newStr=mStr+"/";
      vmStr.push_back(newStr);
      size_t found;
      while(mStr.find_last_of("/")!=string::npos){
	found=mStr.find_last_of("/");
	mStr.erase(mStr.begin()+found, mStr.end());
	string newStr=mStr+"/";
	vmStr.push_back(newStr);
      }
    }
    int nmkdir=0;
    for(int iM=0; iM<vmStr.size(); iM++) {
      if(!ParentDirExist(vmStr.at(iM), vnStr)) {
	nmkdir++;
        vnStr.push_back(vmStr.at(iM));
      }
    }

    vnStr.erase(vnStr.begin(),vnStr.end());
    vmStr.erase(vmStr.begin(),vmStr.end());
    cout << "Case #" << iT+1 << ": " << nmkdir << endl; 
 }
  return 0;
}
