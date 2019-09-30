
import math

class ajanjakso:
  start = 0
  end = 0
  ylitys = False

def testaa_vali(start, end, lista):
  for node in lista:
    if(start > node.end or end < node.start):
      #ei osu
      pass;
    else:
      return True; #osuma!
  return False;

t = int(input())
for i in range(1, t + 1):
  AJ, AC = [int(s) for s in  input().split(" ")];
  #print("gola:{}".format(goal))
  #data containers
  AJ_times = [ajanjakso() for h in range(AJ)]
  AC_times = [ajanjakso() for h in range(AC)]

  free_ac_time = 720;
  free_aj_time = 720;
  #read input
  for h in range(0, AJ):
    s, e = [int(s) for s in input().split(" ")];
    AJ_times[h].start = s;
    AJ_times[h].end = e;
    free_aj_time -= e - s;
  for h in range(0, AC):
    s, e = [int(s) for s in input().split(" ")];
    AC_times[h].start = s;
    AC_times[h].end = e;
    free_ac_time -= e - s;
  AC_times.sort(key=lambda x: x.start);
  AJ_times.sort(key=lambda x: x.start);
  #for h in range(len (AC_times)):
  #  print("Ac time " + str(AC_times[h].start));

  if((len(AC_times) == 1 or len(AC_times) == 0) and (len(AJ_times) == 0 or len(AJ_times) == 1)):
    #ratkaistu
    total = 2;
  else:
    #Yhdistä ac ajat mahdollisimman optimisti
    #etsi mahdollisimman lyhyt, jossa ei AJ välissä
    #FIX AC:
    muutos = True;
    while muutos:
      muutos = False
      lyhin = -1
      lyhin_index = -1
      for ac in range(0,len(AC_times)):
        #viimeinen on spessu
        if(ac < len(AC_times) - 1):
          start = AC_times[ac].end
          end = AC_times[ac+1].start
          osuu = testaa_vali(start,end, AJ_times);
          if(not osuu):
            #mittaa pituus ja etsi lyhin
            pituus = end - start
            if(lyhin == -1 or pituus < lyhin):
              lyhin = pituus;
              lyhin_index = ac;
        else: #viimeinen
          if(AC_times[0].ylitys):
            start = AC_times[ac].end
            end = AC_times[0].start
            osuu = testaa_vali(start,end, AJ_times);
            if(not osuu):
              #mittaa pituus ja etsi lyhin
              pituus = end - start
              if(lyhin == -1 or pituus < lyhin):
                lyhin = pituus;
                lyhin_index = ac;
          else:
            start = AC_times[ac].end
            end = 1440 #mid night
            osuu = testaa_vali(start, end, AJ_times);
            if(not osuu):
              start2 = 0;
              end2 = AC_times[0].start
              osuu = testaa_vali(start2,end2, AJ_times);
              if(not osuu):
                pituus = end - start + end2 - start2;
                if(lyhin == -1 or pituus < lyhin):
                  lyhin = pituus;
                  lyhin_index = ac;
      #nyt lyhin on lyhin pituus
      if(lyhin != -1 and lyhin <= free_ac_time):
        muutos = True;
        #yhdistä kaksi:
        free_ac_time -= lyhin;
        if(lyhin_index != len(AC_times)-1):
          AC_times[lyhin_index].end = AC_times[lyhin_index+1].end;
          AC_times.pop(lyhin_index + 1);
        else: #viimeinen
          AC_times[0].start = AC_times[len(AC_times) - 1].start
          AC_times.pop(len(AC_times) - 1);
          AC_times[0].ylitys = True
    #FIX AJ
    muutos = True;
    while muutos:
      muutos = False
      lyhin = -1
      lyhin_index = -1
      for ac in range(0,len(AJ_times)):
        #viimeinen on spessu
        if(ac < len(AJ_times) - 1):
          start = AJ_times[ac].end
          end = AJ_times[ac+1].start
          osuu = testaa_vali(start,end, AC_times);
          if(not osuu):
            #mittaa pituus ja etsi lyhin
            pituus = end - start
            if(lyhin == -1 or pituus < lyhin):
              lyhin = pituus;
              lyhin_index = ac;
        else: #viimeinen
          if(AJ_times[0].ylitys):
            start = AJ_times[ac].end
            end = AJ_times[0].start
            osuu = testaa_vali(start,end, AC_times);
            if(not osuu):
              #mittaa pituus ja etsi lyhin
              pituus = end - start
              if(lyhin == -1 or pituus < lyhin):
                lyhin = pituus;
                lyhin_index = ac;
          else:
            start = AJ_times[ac].end
            end = 1440 #mid night
            osuu = testaa_vali(start, end, AC_times);
            if(not osuu):
              start2 = 0;
              end2 = AJ_times[0].start
              osuu = testaa_vali(start2,end2, AC_times);
              if(not osuu):
                pituus = end - start + end2 - start2;
                if(lyhin == -1 or pituus < lyhin):
                  lyhin = pituus;
                  lyhin_index = ac;
      #nyt lyhin on lyhin pituus
      if(lyhin != -1 and lyhin <= free_aj_time):
        muutos = True;
        #yhdistä kaksi:
        free_aj_time -= lyhin;
        if(lyhin_index != len(AJ_times)-1):
          AJ_times[lyhin_index].end = AJ_times[lyhin_index+1].end;
          AJ_times.pop(lyhin_index + 1);
        else: #viimeinen
          AJ_times[0].start = AJ_times[len(AJ_times) - 1].start
          AJ_times.pop(len(AJ_times) - 1);
          AJ_times[0].ylitys = True
    total = -1;
    #print("Case #{}: ac:{}, aj:{}".format(i, len(AC_times), len(AJ_times)));
    isompi = max(len(AC_times), len(AJ_times));
    if(isompi == 1 or isompi == 0):
      total = 2
    else:
      total = isompi * 2;


  #solve

  print("Case #{0:.0f}: {1:.0f}".format(i, total));









