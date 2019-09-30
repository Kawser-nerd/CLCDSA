using System;

namespace ABC039
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			MainClass MC = new MainClass ();
			string key_color_array = Console.ReadLine ();
			int[] ww_place_num = new int[5];
			MC.search_WW (key_color_array, ref ww_place_num);
			MC.get_position(ww_place_num);

		}

		void search_WW (string target, ref int[] place_num)
		{
			int i, count = 0;
			for (i = 0; i < target.Length; i++) {
				if (i < target.Length - 1 && target [i] == 'W' && target [i + 1] == 'W') {
					place_num [count] = i;
					count++;
				} 
			}

		}

		void get_position (int[] place_num)
		{
			// The number is decided by the distance between initial term and "ww"-place.
			if (place_num [0] == 0 && place_num [1] == 5 && place_num [2] == 12) {
				Console.WriteLine ("Si");
			} else if (place_num [0] == 6 && place_num [1] == 11 && place_num [2] == 18) {
				Console.WriteLine ("Fa");
			} else if (place_num [0] == 0 && place_num [1] == 7 && place_num [2] == 12) {
				Console.WriteLine ("Mi");
			} else if (place_num [0] == 4 && place_num [1] == 11 && place_num [2] == 16) {
				Console.WriteLine ("Do");
			} else if (place_num [0] == 4 && place_num [1] == 9 && place_num [2] == 16) {
				Console.WriteLine ("So");
			} else if (place_num [0] == 2 && place_num [1] == 9 && place_num [2] == 14) {
				Console.WriteLine ("Re");
			} else if (place_num [0] == 2 && place_num [1] == 7 && place_num [2] == 14) {
				Console.WriteLine ("La");
			}

		} 
	}
}