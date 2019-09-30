using System;
class Program {
  static void Main(string[] args) {
    Program pg = new Program();
    int[] nums = pg.Ret_frm_str(Console.ReadLine().Split(' '));
    int a_b = nums[0] * nums[1];
    for (int cnt = 1; cnt < 4; cnt++) {
      if (a_b * cnt % 2 == 1) {
        Console.WriteLine("Yes");
        break;
      } else {
        if (cnt == 3) {
          Console.WriteLine("No");
        }
      }
    }
  }
  
  private int[] Ret_frm_str (string[] str) {
    return new int[] { int.Parse(str[0]), int.Parse(str[1]) };
  } 
}