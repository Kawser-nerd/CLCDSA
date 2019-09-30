using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Pseudominion : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                int handCount = int.Parse(Console.ReadLine());
                string[] handCards = new string[handCount];
                for (int i = 0; i < handCount; i++)
                {
                    handCards[i] = Console.ReadLine();
                }
                int deckCount = int.Parse(Console.ReadLine());
                string[] deckCards = new string[deckCount];
                for (int i = 0; i < deckCount; i++)
                {
                    deckCards[i] = Console.ReadLine();
                }
                long ret = maxScore(handCards, deckCards);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        string[] deckCards;
        Dictionary<HandState, int> mem;

        private int maxScore(string[] handCards, string[] deckCards)
        {
            this.deckCards = deckCards;
            this.mem = new Dictionary<HandState, int>();
            HandState state = new HandState();
            state.Turns = 1;

            int initialScore = 0;
            for (int i = 0; i < handCards.Length; i++)
            {
                string card = handCards[i];
                int cardc = int.Parse(card.Split(' ')[0]);
                int cards = int.Parse(card.Split(' ')[1]);
                int cardt = int.Parse(card.Split(' ')[2]);
                if (cardt > 0)
                {
                    initialScore += cards;
                    state.InitialCards += cardc;
                    state.Turns += cardt - 1;
                }
                else
                {
                    state.Scores[cardc].Add(cards);
                }
            }

            for (int i = 0; i < 3; i++)
            {
                state.Scores[i].Sort();
            }

            return initialScore + bestScore(state);
        }

        private int bestScore(HandState state)
        {
            int ret;
            if (mem.TryGetValue(state, out ret))
            {
                return ret;
            }
            if (state.Turns == 0) return 0;

            ret = 0;

            for (int c = 0; c < 4; c++)
            {
                if (c < 3 && state.InitialCards > 0) continue;
                if (c == 3 && state.InitialCards == 0) continue;
                if (c < 3 && state.Scores[c].Count == 0) continue;

                HandState newState = state.Clone();
                int score = 0;
                int carddraws = state.InitialCards;
                newState.InitialCards = 0;
                if (c < 3)
                {
                    score = newState.Scores[c][newState.Scores[c].Count - 1];
                    carddraws += c;
                    newState.Turns--;
                    newState.Scores[c].RemoveAt(newState.Scores[c].Count - 1);
                }

                while (carddraws > 0 && newState.DeckTopIdx < this.deckCards.Length)
                {
                    carddraws--;
                    string newcard = deckCards[newState.DeckTopIdx++];
                    int newcardc = int.Parse(newcard.Split(' ')[0]);
                    int newcards = int.Parse(newcard.Split(' ')[1]);
                    int newcardt = int.Parse(newcard.Split(' ')[2]);
                    if (newcardt > 0 && newState.Turns > 0)
                    {
                        // immediately play this, don't add it to state
                        score += newcards;
                        carddraws += newcardc;
                        newState.Turns += newcardt - 1;
                    }
                    else
                    {
                        newState.Scores[newcardc].Add(newcards);
                    }
                }

                // We have finished drawing, or the deck has run out
                if (newState.DeckTopIdx == this.deckCards.Length)
                {
                    // card draws are irrelevant
                    newState.Scores[0].AddRange(newState.Scores[1]);
                    newState.Scores[0].AddRange(newState.Scores[2]);
                    newState.Scores[1] = new List<int>();
                    newState.Scores[2] = new List<int>();
                }

                for (int i = 0; i < 3; i++)
                {
                    newState.Scores[i].Sort();
                }

                score += bestScore(newState);
                ret = Math.Max(ret, score);
            }
            mem[state] = ret;
            return ret;
        }

        private class HandState
        {
            public List<int>[] Scores;
            public int Turns;
            public int DeckTopIdx;

            public int InitialCards;

            public HandState()
            {
                Scores = new List<int>[3];
                Scores[0] = new List<int>();
                Scores[1] = new List<int>();
                Scores[2] = new List<int>();
            }

            public HandState Clone()
            {
                HandState ret = new HandState();
                ret.DeckTopIdx = this.DeckTopIdx;
                ret.Turns = this.Turns;
                ret.InitialCards = this.InitialCards;

                for (int i = 0; i < 3; i++)
                {
                    ret.Scores[i] = this.Scores[i].ToList();
                }
                return ret;
            }


            public override bool Equals(object obj)
            {
                HandState otherHand = (HandState)obj;
                if (this.Turns != otherHand.Turns) return false;
                if (this.DeckTopIdx != otherHand.DeckTopIdx) return false;
                if (this.InitialCards != otherHand.InitialCards) return false;
                for (int i = 0; i < 3; i++)
                {
                    if (this.Scores[i].Count != otherHand.Scores[i].Count) return false;
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < this.Scores[i].Count; j++)
                    {
                        if (this.Scores[i][j] != otherHand.Scores[i][j]) return false;
                    }
                }
                return true;
            }

            public override int GetHashCode()
            {
                int hash = 0;
                hash ^= this.Turns;
                hash *= 1007;
                hash ^= this.DeckTopIdx;
                hash *= 1007;
                hash ^= this.InitialCards;
                hash *= 1007;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < this.Scores[i].Count; j++)
                    {
                        hash ^= Scores[i][j];
                        hash *= 1009;
                    }
                    hash *= 997;
                }
                return hash;
            }

            public override string ToString()
            {
                return base.ToString();
            }
        }

    }
}
