using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Magicka
{
    class Program
    {
        class TestCase
        {
            struct Combine
            {
                public Combine( char other, char result )
                {
                    mOther = other;
                    mResult = result;
                }

                public char mOther;
                public char mResult;
            }

            struct Oppose
            {
                public Oppose( char other )
                {
                    mOther = other;
                }
                public char mOther;
            }

            List<List<Combine>> mCombiners = new List<List<Combine>>();
            List<List<Oppose>> mOpposers = new List<List<Oppose>>();
            List<char> mResult = new List<char>();

            public TestCase( int caseNum )
            {
                for ( int x = 0; x < 'Z' - 'A' + 1; ++x )
                {
                    mCombiners.Add( new List<Combine>() );
                    mOpposers.Add( new List<Oppose>() );
                }

                string line = Console.ReadLine();
                string[] input = line.Split( " ".ToCharArray() );
                int i = 0;
                int numCombines = int.Parse( input[i++] );
                for ( int c = 0; c < numCombines; c++ )
                {
                    char inputA = input[i][0];
                    char inputB = input[i][1];
                    char result = input[i][2];

                    mCombiners['Z' - inputA].Add( new Combine( inputB, result ) );
                    mCombiners['Z' - inputB].Add( new Combine( inputA, result ) );

                    ++i;
                }

                int numOpposers = int.Parse( input[i++] );
                for ( int o = 0; o < numOpposers; o++ )
                {
                    char inputA = input[i][0];
                    char inputB = input[i][1];

                    mOpposers['Z' - inputA].Add( new Oppose( inputB ) );
                    mOpposers['Z' - inputB].Add( new Oppose( inputA ) );

                    ++i;
                }

                // don't bother with the length
                ++i;

                string magicStream = input[i];

                SolveMagic( magicStream );

                Console.Write( "Case #{0}: ", caseNum );
                Console.Write( "[" );
                bool first = true;
                foreach ( char c in mResult )
                {
                    if ( !first )
                    {
                        Console.Write(", ");
                    }

                    first = false;
                    Console.Write("{0}", c);
                }
                Console.WriteLine("]");
            }

            void SolveMagic( string magicStream )
            {
                foreach ( char element in magicStream )
                {
                    if ( mResult.Count > 0 )
                    {
                        bool combined = false;

                        foreach ( Combine combine in mCombiners['Z' - element] )
                        {
                            if ( combine.mOther == mResult[mResult.Count - 1] )
                            {
                                //Console.WriteLine( "Combine: {0} {1} into {2}", element, combine.mOther, combine.mResult );
                                mResult[mResult.Count - 1] = combine.mResult;
                                combined = true;
                                break;
                            }
                        }

                        if ( combined )
                        {
                            continue;
                        }

                        bool opposed = false;

                        foreach ( Oppose oppose in mOpposers['Z' - element] )
                        {
                            if ( mResult.Contains( oppose.mOther ) )
                            {
                                //Console.WriteLine( "Oppose: {0} and {1}", element, oppose.mOther );
                                mResult.Clear();
                                opposed = true;
                                break;
                            }
                        }

                        if ( opposed )
                        {
                            continue;
                        }
                    }

                    //Console.WriteLine( "Add: {0}", element );
                    mResult.Add( element );
                }
            }
        }

        static void Main( string[] args )
        {
            int testCases = int.Parse( Console.ReadLine() );
            for ( int i = 0; i < testCases; ++i )
            {
                new TestCase( i + 1 );
            }

            Console.ReadLine();
        }
    }
}
