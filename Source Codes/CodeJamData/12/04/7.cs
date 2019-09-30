using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

//raytracer z lustrami, to jak Duke Nukem Andrzeju!

namespace mirrors
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var input = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var height = input[0];
                    int width = input[1];
                    int fog = input[2];

                    int playerX = -1, playerY = -1;
                    var mirrors = new bool[width,height];
                    for (var i = 0; i < height; i++)
                    {
                        var line = inputStream.ReadLine();
                        for (var j = 0; j < width; j++)
                        {
                            mirrors[j, i] = line[j] == '#';
                            if (line[j] == 'X')
                            {
                                playerX = j;
                                playerY = i;
                            }
                        }
                    }

                    var reflections = 0;
                    for (var targetY = playerY - fog; targetY <= playerY + fog; targetY++)
                        for (var targetX = playerX - fog; targetX <= playerX + fog; targetX++)
                        {
                            var realDistanceSquare = (targetX - playerX) * (targetX - playerX) + (targetY - playerY) * (targetY - playerY);
                            if (realDistanceSquare <= fog * fog && realDistanceSquare > 0)
                            {
                                if (TraceRay(mirrors, playerX, playerY, targetX, targetY))
                                    reflections++;
                            }
                        }

                    outputStream.WriteLine("Case #{0}: {1}", currentCase, reflections);
                }

            }
        }

        public enum RayEvent
        {
            X,
            Y,
            XY,
            Center
        }

        public static bool TraceRay(bool[,] mirrors, int startX, int startY, int finishX, int finishY)
        {
            var deltaX = finishX - startX;
            var deltaY = finishY - startY;
            var virtualDirectionX = deltaX >= 0 ? 1 : -1;
            var virtualDirectionY = deltaY >= 0 ? 1 : -1;
            if (deltaX < 0)
                deltaX = -deltaX;
            if (deltaY < 0)
                deltaY = -deltaY;

            var virtualX = startX;
            var virtualY = startY;
            var mapX = startX;
            var mapY = startY;
            var mapDirectionX = virtualDirectionX;
            var mapDirectionY = virtualDirectionY;

            var rayEvents = GenerateRayEvents(deltaX, deltaY);
            for (var i = 0; i < rayEvents.Count; i++)
            {
                var rayEvent = rayEvents[i];
                switch (rayEvent)
                {
                    case RayEvent.X:
                        virtualX += virtualDirectionX;
                        if (mirrors[mapX + mapDirectionX, mapY])
                        {
                            mapDirectionX = -mapDirectionX;
                        }
                        else
                        {
                            mapX += mapDirectionX;
                        }
                        break;
                    case RayEvent.Y:
                        virtualY += virtualDirectionY;
                        if (mirrors[mapX, mapY + mapDirectionY])
                        {
                            mapDirectionY = -mapDirectionY;
                        }
                        else
                        {
                            mapY += mapDirectionY;
                        }
                        break;
                    case RayEvent.XY:
                        virtualX += virtualDirectionX;
                        virtualY += virtualDirectionY;
                        if (!mirrors[mapX + mapDirectionX, mapY + mapDirectionY])
                        {
                            mapX += mapDirectionX;
                            mapY += mapDirectionY;
                        }
                        else
                        {
                            if (!mirrors[mapX + mapDirectionX, mapY] && !mirrors[mapX, mapY + mapDirectionY])
                                return false;
                            if (mirrors[mapX + mapDirectionX, mapY])
                            {
                                mapDirectionX = -mapDirectionX;
                            }
                            else
                            {
                                mapX += mapDirectionX;
                            }
                            if (mirrors[mapX, mapY + mapDirectionY])
                            {
                                mapDirectionY = -mapDirectionY;
                            }
                            else
                            {
                                mapY += mapDirectionY;
                            }
                        }
                        break;
                    case RayEvent.Center:
                        if (mapX == startX && mapY == startY)
                        {
                            if (i == rayEvents.Count - 1)
                                return true;
                            else
                                return false;
                        }
                        break;
                }
            }

            return false;
        }

        public static List<RayEvent> GenerateRayEvents(int targetX, int targetY)
        {
            var result = new List<RayEvent>();
            int stopX, stopY;
            bool reversed;
            if (targetX >= targetY)
            {
                stopX = targetX * 2;
                stopY = targetY * 2;
                reversed = false;
            }
            else
            {
                stopX = targetY * 2;
                stopY = targetX * 2;
                reversed = true;
            }

            var previousY = 0;
            for (var x = 1; x <= stopX; x++)
            {
                if (x % 2 == 1)
                {
                    var currentY = stopY * x / stopX;
                    var exactlyOnY = stopY * x % stopX == 0;
                    if ((currentY + 1) / 2 > (previousY + 1) / 2)
                    {
                        if (exactlyOnY && currentY % 2 == 1)
                            result.Add(RayEvent.XY);
                        else
                        {
                            if (!reversed)
                            {
                                result.Add(RayEvent.Y);
                                result.Add(RayEvent.X);
                            }
                            else
                            {
                                result.Add(RayEvent.X);
                                result.Add(RayEvent.Y);
                            }
                        }
                    }
                    else
                    {
                        if (!reversed)
                            result.Add(RayEvent.X);
                        else
                            result.Add(RayEvent.Y);
                    }
                    previousY = currentY;
                }
                else
                {
                    var currentY = stopY * x / stopX;
                    var exactlyOnY = stopY * x % stopX == 0;
                    if (exactlyOnY && currentY % 2 == 0)
                        result.Add(RayEvent.Center);
                }
            }
            return result;
        }
    }
}
