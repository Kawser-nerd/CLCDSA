using System;

namespace ABC001
{
    public class ABC001_C
    {
        static void Main(string[] args)
        {
            ABC001_C instance = new ABC001_C();
            instance.Answer();
        }

        private void Answer()
        {
            var inputs = Console.ReadLine().Split(' ');
            
            int windDegree = int.Parse(inputs[0]);
            int windDistance = int.Parse(inputs[1]);

            string windDirection = GetWindDirectionStr(windDegree,windDistance);
            string windPower = GetWindPowerStr(windDistance);
            
            Console.WriteLine($"{windDirection} {windPower}");
        }

        private string GetWindDirectionStr(int windDegree, int windDistance)
        {
            string windPower = GetWindPowerStr(windDistance);
            if (windPower.Equals("0"))
            {
                return "C";
            }
            
            windDegree *= 10;

            if (windDegree >= 34875)
            {
                return "N";
            }

            if (windDegree >= 32625)
            {
                return "NNW";
            }

            if (windDegree >= 30375)
            {
                return "NW";
            }

            if (windDegree >= 28125)
            {
                return "WNW";
            }

            if (windDegree >= 25875)
            {
                return "W";
            }

            if (windDegree >= 23625)
            {
                return "WSW";
            }

            if (windDegree >= 21375)
            {
                return "SW";
            }

            if (windDegree >= 19125)
            {
                return "SSW";
            }

            if (windDegree >= 16875)
            {
                return "S";
            }

            if (windDegree >= 14625)
            {
                return "SSE";
            }

            if (windDegree >= 12375)
            {
                return "SE";
            }

            if (windDegree >= 10125)
            {
                return "ESE";
            }

            if (windDegree >= 7875)
            {
                return "E";
            }

            if (windDegree >= 5625)
            {
                return "ENE";
            }

            if (windDegree >= 3375)
            {
                return "NE";
            }

            if (windDegree >= 1125)
            {
                return "NNE";
            }

            return "N";
        }

        private string GetWindPowerStr(int windDistance)
        {
            float msWindDistance = windDistance / 60.0f;
            msWindDistance *= 100;
            msWindDistance += 5;
            int windPower = (int) (msWindDistance / 10.0f);

            if (windPower >= 327)
            {
                return "12";
            }

            if (windPower >= 285)
            {
                return "11";
            }

            if (windPower >= 245)
            {
                return "10";
            }

            if (windPower >= 208)
            {
                return "9";
            }

            if (windPower >= 172)
            {
                return "8";
            }

            if (windPower >= 139)
            {
                return "7";
            }

            if (windPower >= 108)
            {
                return "6";
            }

            if (windPower >= 80)
            {
                return "5";
            }

            if (windPower >= 55)
            {
                return "4";
            }

            if (windPower >= 34)
            {
                return "3";
            }

            if (windPower >= 16)
            {
                return "2";
            }

            if (windPower >= 3)
            {
                return "1";
            }


            return "0";
        }
    }
}