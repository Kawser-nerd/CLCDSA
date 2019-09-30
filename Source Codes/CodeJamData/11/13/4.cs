using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Globalization;
using System.IO;

namespace Test
{
   class Program
   {
      static int lineI = 0;
      static void Main(string[] args)
      {
         checkProblem();
      }

      struct Card {
         public int c;
         public int s;
         public int t;

         public override String ToString() {
            return "c: " + c + " s: " + s + " t: " + t;
         }
      }

      struct State {
         public int turnsLeft;
         public int score;

         public override String ToString() {
            return "Turns: " + turnsLeft + " Score: " + score;
         }
      }

      public static void AllString<T>(List<T> objs) {
         foreach(T obj in objs) {
            Console.WriteLine(obj.ToString());
         }
      }

      private static Card parseCard(String[] lines) {
         String line = lines[lineI++];
         String[] parts = line.Split(new char[] {' '});

         Card c;
         c.c = int.Parse(parts[0]);
         c.s = int.Parse(parts[1]);
         c.t = int.Parse(parts[2]);

         return c;
      }

      private static State playCard(int i, List<Card> hand, List<Card> deck, State cur) {
         if(cur.turnsLeft == 0) {
            throw new Exception("WTF? NO TURNS LEFT");
         }
         cur.turnsLeft--;

         // take the card and remove it
         Card c = hand[i];
         hand.RemoveAt(i);

         // add score + turns from card
         cur.score += c.s;
         cur.turnsLeft += c.t;
         
         // get some cards from the deck and put in the hand
         int numDeck = 0;
         while(numDeck < c.c && deck.Count > 0) {
            hand.Add(deck[0]);
            deck.RemoveAt(0);
            numDeck++;
         }

         return cur;
      }


      private static int highestScore(List<Card> hand, List<Card> deck, State s) {
         if(hand.Count == 0) return s.score;
         if(s.turnsLeft == 0) return s.score;


         // if we have a card that has t > 0, ALWAYS play it
         for(int i = 0; i < hand.Count; i++) {
            if(hand[i].t > 0) {
               State tS = playCard(i, hand, deck, s);
               return highestScore(hand, deck, tS);
            }
         }

         // if there's no cards in the deck or we have a single turn left, play the scorers.
/*
         bool shouldPlayHighest = false;

         if(deck.Count == 0) {
            shouldPlayHighest = true;
         } else {
            // if all your cards have c == 0, then pick the highest scorer)
            shouldPlayHighest = true;
            for(int i = 0; i < hand.Count; i++) {
               if(hand[i].c > 0) {
                  shouldPlayHighest = false;
                  break;
               }
            }

         }

         if(shouldPlayHighest && false) {
            int largestScorer = 0;
            int largestScorerI = -1;
            for(int i = 0; i < hand.Count; i++) {
               if(hand[i].s > largestScorer) {
                  largestScorer = hand[i].s;
                  largestScorerI = i;
               }
               if(largestScorerI != -1) {
                  State tS = playCard(largestScorerI, hand, deck, s);
                  return highestScore(hand, deck, tS);
               }
            }
         }
*/

         // make a list of cards worth trying, best in that [num cards to pick up]
         Dictionary<int, int> bestScorer = new Dictionary<int, int>();
         Dictionary<int, int> bestI = new Dictionary<int, int>();

         for(int i = 0; i < 3; i++) {
            bestScorer[i] = -1;
            bestI[i] = -1;
         }

         for(int i = 0; i < hand.Count; i++) {
            Card c = hand[i];
            if(bestScorer[c.c] < c.s) {
               bestScorer[c.c] = c.s;
               bestI[c.c] = i;
            }
         }

         // otherwise, we try playing any of our best scorer cards
         int maxScore = -1;
         for(int i = 0; i < 3; i++) {
            if(bestI[i] != -1) {
               List<Card> tHand = new List<Card>(hand);
               List<Card> tDeck = new List<Card>(deck);

               if(bestScorer[i] != tHand[bestI[i]].s) {
                  throw new Exception("WTF!");
               }
               if(tHand[bestI[i]].t > 0) {
                  throw new Exception("WTF!");
               }

               State tS = playCard(bestI[i], tHand, tDeck, s);
               // see how we can improve this score now!
               int ms = highestScore(tHand, tDeck, tS);
               if(maxScore == -1 || ms > maxScore) {
                  maxScore = ms;
               }
            }
         }

         return maxScore;
      }

      private static String doProblem(String[] lines) {
         int numMine = int.Parse(lines[lineI++]);

         Card[] myCards = new Card[numMine];
         for(int i = 0; i < numMine; i++) {
            myCards[i] = parseCard(lines);
         }

         int numDeck = int.Parse(lines[lineI++]);
         Card[] deckCards = new Card[numDeck];
         for(int i = 0; i < numDeck; i++) {
            deckCards[i] = parseCard(lines);
         }

         List<Card> hand = new List<Card>(myCards);
         List<Card> deck = new List<Card>(deckCards);

         State s;
         s.turnsLeft = 1;
         s.score = 0;

         Console.WriteLine("Hand:");
         AllString(hand);
         Console.WriteLine("Deck:");
         AllString(deck);


         return highestScore(hand, deck, s).ToString();
      }


      private static void checkProblem()
      {

         String output = "";
         String[] lines = File.ReadAllLines("input");
         int numCases = int.Parse(lines[0]);
         lineI++;
         for (int i = 1; i <= numCases; i++ )
         {
            Console.WriteLine("CASE NUMBER " + i);
            String myoutput = doProblem(lines);
            Console.WriteLine("Output was: " + myoutput);

            output += ("Case #" + i + ": " + myoutput);
            output += "\n";
         }

         Console.WriteLine("----Output----");
         Console.WriteLine(output);

         File.WriteAllText("output", output);
      }
   }
}
