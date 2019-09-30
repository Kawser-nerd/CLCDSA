using System;
using System.Collections.Generic;

namespace atcoder_ABC065B
{
    class MainClass
    {
        public static void Main(string[] args)
        {
			int buttonCount = int.Parse(Console.ReadLine());
			Dictionary<string, string> lightPatterns = new Dictionary<string, string>();
			for (int i = 0; i < buttonCount; i++)
			{
				lightPatterns[(i + 1).ToString()] = Console.ReadLine();
			}

			int pushCount = 0;
			string lightingButton = "1";
            while (true)
			{
				if (!lightPatterns.ContainsKey(lightingButton)) {
					Console.WriteLine("-1"); 
					return;	
				}

				string pushedButton = lightingButton;

				lightingButton = lightPatterns[lightingButton];
				lightPatterns.Remove(pushedButton);

				pushCount++;

				if (lightingButton == "2") {
					Console.WriteLine(pushCount); 
					return;	
				}
			}
        }
    }
}