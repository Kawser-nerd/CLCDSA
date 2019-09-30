#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int solve_simple();

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
    cout<<"Case #"<<i+1<<": "<<solve_simple()<<'\n';
}

struct card{
  int draw,points,turns;
  void read();
};

int simulate(vector<card> hand,const vector<card>& deck,int draws);

int solve_simple(){
  int hand_size,deck_size;
  cin>>hand_size;
  vector<card> hand(hand_size);
  for(int h=0;h<hand.size();h++)
    hand[h].read();
  cin>>deck_size;
  vector<card> deck(deck_size);
  for(int d=0;d<deck.size();d++)
    deck[d].read();
  int best=0;
  for(int draws=0;draws<=deck.size();draws++)
    best=max(best,simulate(hand,deck,draws));
  return best;
}

card choose(vector<card>& hand,int index){
  card ret=hand[index];
  hand.erase(hand.begin()+index);
  return ret;
}

const int bad=-1;

card choose_simple_best(vector<card>& hand,bool must_draw){
  int best_score=bad,best_index;
  for(int h=0;h<hand.size();h++){
    if(hand[h].turns>0)
      return choose(hand,h);
    if(must_draw && hand[h].draw==0)
      continue;
    if(hand[h].points>best_score){
      best_score=hand[h].points;
      best_index=h;
    }
  }
  if(best_score==bad){
    assert(must_draw);
    return choose_simple_best(hand,false);
  }
  return choose(hand,best_index);
}

int simulate(vector<card> hand,const vector<card>& deck,int draws){
  int turns=1,score=0,next=0;
  while(turns>0 && hand.size()>0){
    turns--;
    card now=choose_simple_best(hand,draws>0);
    score+=now.points;
    turns+=now.turns;
    while(now.draw && draws>0){
      assert(next<deck.size());
      draws--;
      hand.push_back(deck[next++]);
      now.draw--;
    }
  }
  return score;
}

void card::read(){
  cin>>draw>>points>>turns;
}
