#include <iostream>
#include <vector>
#include <stdexcept>
#include <ostream>
#include <utility>
#include <type_traits>
#include <valarray>

using std::cout;
using std::cin;
using std::endl;

//matrix,tensor???
template<typename T>
using ve = std::vector<T>;

template<typename T>
using ma = ve<ve<T> >;

template<typename T>
using te = ve<ma<T> >;

template<bool condition>
using enable_if_type = typename std::enable_if<condition,std::nullptr_t>::type;

//ve?????????<<????????(????)
//+
template<typename T1, typename T2>
ve<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const ve<T1>& self,const ve<T2>& other);

//-
template<typename T1, typename T2>
ve<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const ve<T1>& self,const ve<T2>& other);

//ve * scholar
template<typename T1 ,typename T2, enable_if_type<std::is_arithmetic<T2>::value> = nullptr>
ve<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const ve<T1>& self,const T2& other);

//scholar * ve
template<typename T1, typename T2, enable_if_type<std::is_arithmetic<T1>::value> = nullptr>
ve<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const T1& self,const ve<T2>& other);

//ve * ve
template<typename T1, typename T2>
ve<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const ve<T1>& self,const ve<T2>& other);

// ve / ve
template<typename T1, typename T2>
ve<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const ve<T1>& self,const ve<T2>& other);

// ve / scholar
template<typename T1, typename T2, enable_if_type<std::is_arithmetic<T2>::value> = nullptr>
ve<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const ve<T1>& self,const T2& other);

// scholar / ve
template<typename T1, typename T2, enable_if_type<std::is_arithmetic<T1>::value> = nullptr>
ve<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const T1& self,const ve<T2>& other);

// << ve<scholar>
template<typename T, enable_if_type<std::is_arithmetic<T>::value> = nullptr>
std::ostream& operator<<(std::ostream& os, const ve<T>& self);

// << ma,te
template<typename T, enable_if_type<not(std::is_arithmetic<T>::value)> = nullptr>
std::ostream& operator<<(std::ostream& os, const ve<T>& self);

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

int main(){
  bool result;
  std::int64_t n,total(0),step,stones;
  cin >> n;
  std::valarray<std::int64_t> box(n),diff(n),temp(n);
  for(std::size_t i = 0; i < n; ++i){
    cin >> box[i];
    total += box[i];
  }
  diff = box.cshift(1) - box;
  stones = ((n*(n+1))/2);
  if(total % stones != 0)
    result = false;
  else{
    step = total / stones;
    //    cout << "step " << step << endl;
    diff -= step;
    temp = diff % n;
    /*
    cout << "diff ";
    for(int i = 0; i < n; ++i)
      cout << diff[i] << " ";
    cout << endl;

    cout << "temp ";
    for(int i = 0; i < n; ++i)
      cout << temp[i] << " ";
    cout << endl;
    */
    if(temp.min() != 0 || diff.max() > 0)
      result = false;
    else{
      diff = diff/n;
      if(-diff.sum() ==  step)
	result = true;
      else
	result = false;
    }
  }

  if(result == true)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


//??
//+
template<typename T1, typename T2>
ve<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const ve<T1>& self,const ve<T2>& other){
  if(self.size() != other.size())
    throw std::invalid_argument("You put different size ve.");  
  ve<decltype(std::declval<T1>() + std::declval<T2>())> result(self.size());
  auto resultItr = result.begin();
  auto selfItr = self.cbegin();
  auto otherItr = other.cbegin();
  while(resultItr != result.end() && selfItr != self.cend() &&
	otherItr != other.cend()){
    *resultItr = *selfItr + *otherItr;
    ++resultItr;
    ++selfItr;
    ++otherItr;
  }
  return result;
}

//-
template<typename T1, typename T2>
ve<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const ve<T1>& self,const ve<T2>& other){
  if(self.size() != other.size())
    throw std::invalid_argument("You put different size ve.");
  ve<decltype(std::declval<T1>() - std::declval<T2>())> result;
  result.resize(self.size());
  auto resultItr = result.begin();
  auto selfItr = self.cbegin();
  auto otherItr = other.cbegin();
  while(resultItr != result.end() && selfItr != self.cend() &&
	otherItr != other.cend()){
    *resultItr = *selfItr - *otherItr;
    ++resultItr;
    ++selfItr;
    ++otherItr;
  }  
  return result;
}


//ve * ve
template<typename T1, typename T2>
ve<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const ve<T1>& self,const ve<T2>& other){
  if(self.size() != other.size())
    throw std::invalid_argument("You put different size ve.");  
  ve<decltype(std::declval<T1>() * std::declval<T2>())> result;
  result.resize(self.size());
  auto resultItr = result.begin();
  auto selfItr = self.cbegin();
  auto otherItr = other.cbegin();
  while(resultItr != result.end() && selfItr != self.cend() &&
	otherItr != other.cend()){
    *resultItr = *selfItr * *otherItr;
    ++resultItr;
    ++selfItr;
    ++otherItr;
  }  
  return result;
}

//ve * scholar
template<typename T1 ,typename T2, enable_if_type<std::is_arithmetic<T2>::value> >
ve<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const ve<T1>& self,const T2& other){
  ve<decltype(std::declval<T1>() * std::declval<T2>())> result;
  result.resize(self.size());
  auto resultItr = result.begin();
  auto selfItr = self.cbegin();
  while(resultItr != result.end() && selfItr != self.cend()){
    *resultItr = *selfItr * other;
    ++resultItr;
    ++selfItr;
  }  
  return result;
}

//scholar * ve
template<typename T1, typename T2, enable_if_type<std::is_arithmetic<T1>::value> >
ve<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const T1& self,const ve<T2>& other){
  return other*self;
}

// ve / ve
template<typename T1, typename T2>
ve<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const ve<T1>& self,const ve<T2>& other){
  if(self.size() != other.size())
    throw std::invalid_argument("You put different size ve.");    
  ve<decltype(std::declval<T1>() / std::declval<T2>())> result;
  result.resize(self.size());
  auto resultItr = result.begin();
  auto selfItr = self.cbegin();
  auto otherItr = other.cbegin();
  while(resultItr != result.end() && selfItr != self.cend() &&
	otherItr != other.cend()){
    *resultItr = *selfItr / *otherItr;
    ++resultItr;
    ++selfItr;
    ++otherItr;
  }  
  return result;
}

// ve / scholar
template<typename T1, typename T2, enable_if_type<std::is_arithmetic<T2>::value> >
ve<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const ve<T1>& self,const T2& other){ 
  ve<decltype(std::declval<T1>() / std::declval<T2>())> result;
  result.resize(self.size());
  auto resultItr = result.begin();
  auto selfItr = self.cbegin();
  while(resultItr != result.end() && selfItr != self.cend()){
    *resultItr = *selfItr / other;
    ++resultItr;
    ++selfItr;
  }  
  return result;
}

// scholar / ve
template<typename T1, typename T2, enable_if_type<std::is_arithmetic<T1>::value> >
ve<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const T1& self,const ve<T2>& other){
  ve<decltype(std::declval<T1>() / std::declval<T2>())> result;
  result.resize(other.size());
  auto resultItr = result.begin();
  auto otherItr = other.cbegin();
  while(resultItr != result.end() && otherItr != other.cend()){
    *resultItr = self / *otherItr;
    ++resultItr;
    ++otherItr;
  }    
  return result;
}

// << ve<scholar>
template<typename T, enable_if_type<std::is_arithmetic<T>::value> >
std::ostream& operator<<(std::ostream& os, const ve<T>& self){
  auto itr = self.begin();
  while(itr != self.end() - 1){
    os << *itr << ",";
    ++itr;
  }
  os << *itr << endl;
  return os;
}

// << ma,te
template<typename T, enable_if_type<not(std::is_arithmetic<T>::value)> >
std::ostream& operator<<(std::ostream& os, const ve<T>& self){
  auto itr = self.begin();
  while(itr != self.end() - 1){
    os << *itr;
    ++itr;
  }
  os << *itr << endl;
  return os;
}