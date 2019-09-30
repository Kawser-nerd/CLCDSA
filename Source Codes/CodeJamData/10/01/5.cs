using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

namespace CodeJam2010
{
    public class A
    {
        System.IO.StreamWriter writer = new System.IO.StreamWriter( "d:\\temp\\Aout.txt" );

        public void Solve( )
        {
            ReadInput( );
            writer.Flush( );
        }

        private void ReadInput( )
        {
            string filename = "d:\\temp\\a.in";
            string [ ] strAll = System.IO.File.ReadAllText( filename ).Split(
                new char[ ] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries );

            int T = int.Parse( strAll[ 0 ] );

            for ( int i = 1; i <= T; ++i )
            {
                string [] nk = strAll[ i ].Split(
                    new char[ ] { ' ' },
                    StringSplitOptions.RemoveEmptyEntries );
                int N = int.Parse( nk[ 0 ] );
                int K = int.Parse( nk[ 1 ] );

                ++K;
                bool good = ( K % ( 1L << N ) ) == 0;
                writer.WriteLine( "Case #" + i + ": " + ( good ? "ON" : "OFF" ) );
            }
        }

        static void Main( string[ ] args )
        {
            new CodeJam2010.A( ).Solve( );
        }
    }
}
