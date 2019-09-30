using System;
using System.Collections.Generic;

namespace GCJtest
{
    class Program
    {
        static void Main()
        {
            double R;
            double iR;
            double t;
            double r;
            double g;
            double f;

            int numCases = int.Parse(Console.ReadLine());
            char[] delim = {' ', '\t'};
            
            for(int c = 0; c < numCases; c++) {
                string[] splits = Console.ReadLine().Split(delim, StringSplitOptions.RemoveEmptyEntries);
                
                f = double.Parse(splits[0]);
                R = double.Parse(splits[1]);
                t = double.Parse(splits[2]);
                r = double.Parse(splits[3]);
                g = double.Parse(splits[4]);
                // the effective inner radius (also subtract f)
                iR = R-t-f;

                // can the fly ever escape?
                if ((2.0*f >= g) || (iR <= 0.0)) {
                    Console.WriteLine("Case #{0}: {1:f6}", c+1, 1.0);
                    continue;
                }

                double racketArea = Math.PI * R * R / 4.0;
                double freeArea = 0.0;
                
                // the lattice step 
                double s = 2.0*r + g;
                int latticeSize = (int) Math.Ceiling(iR / s);
                
                double freeSide = g - 2*f;
                double freeSquare = (freeSide) * (freeSide);
                
                // we use the square of the iR alot
                // for inside / outside detection 
                double iRsq = iR * iR;

                // just checking quadrant #1.
                // i,j is the lower left corner
                for (int i = 0; i < latticeSize; i++) {
                    for (int j = 0; j < latticeSize; j++) {
                        // upper right corner of free area inside iR?
                        double rcx = s * (i + 1) - r - f;
                        double ucy = s * (j + 1) - r - f;

                        if ((rcx * rcx + ucy * ucy) < iRsq) {
                            freeArea += freeSquare;
                            continue;
                        }
                        // lower left corner of free square outside iR?
                        double lcx = rcx - freeSide;
                        double lcy = ucy - freeSide;
                        if ((lcx * lcx + lcy * lcy) > iRsq)
                            continue;
                        
                        // otherwise we have an intersection
                        // there are four cases depending on whether ul and lr corners contained
                        // we need to evaluate the integral at the lower and upper limits
                        // we need to add in the area for rectangles not under integral
                        
                        
                        double llim;
                        double ulim;
                        double extra = 0.0;
                        // if the ul corner is outside of iR we start integrating at lcx
                        if ((lcx * lcx + ucy * ucy) > iRsq) {
                            llim = lcx;
                        } else {
                            // we need to know where the iR intersects the top edge of
                            // the freeSquare to begin integration and count the extra
                            double interx = Math.Sqrt(iRsq - ucy * ucy);
                            llim = interx;
                            extra = freeSide * (interx - lcx);
                        }
                        // if the lr corner is inside of iR we stop integrating at rcx
                        if ((rcx * rcx + lcy * lcy) < iRsq) {
                            ulim = rcx;
                        } else {
                            // we need to know where the iR intersects the lower edge of
                            // the freeSquare to stop integration and there is no extra
                            ulim = Math.Sqrt(iRsq - lcy*lcy);
                        }

                        // Now we can add in the extra and evaluate the limits
                        freeArea += extra;
                        freeArea += 0.5 * (ulim * Math.Sqrt(iRsq - ulim * ulim) + iRsq * Math.Asin(ulim / iR));
                        freeArea -= 0.5 * (llim * Math.Sqrt(iRsq - llim * llim) + iRsq * Math.Asin(llim / iR));
                        // We need to ignore area below y = lcy;
                        freeArea -= (ulim - llim) * lcy;
                    }
                }
                double probability = 1.0 - freeArea / racketArea;
                Console.WriteLine("Case #{0}: {1:f6}", c+1, probability);
            }
        }
    }
}

