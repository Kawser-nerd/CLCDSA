using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
  
namespace ChomadoAtCoder
{
  class Chomado
  {
    public Chomado() {}
    public static int Main()
    {
      new Chomado().Calc ();
      return 0;
    }
  
    void Calc()
    {
      var inputs = InputValues;
      var count = inputs
        .Where (i => i.Contains ('r'))
        .Count ();
      Console.WriteLine (count);
    }
  
    // ????????? List<string> ?????
    List<string> InputValues
    {
      get
      { 
        var inputs = new List<string> ();
 
        // ??????????????
        while (true)
        {
          string input = Console.ReadLine ();
          if (input == null)
            break;
          else
            inputs.Add (input);
        };
        return inputs;
      }
    }
  }
}