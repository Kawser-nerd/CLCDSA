#       )                         .MMdMMM;                    .M#(,dM]                        .:
#       )                        .M@d@d#Mb                    dMGMM(MN                        .:
#       )                        dM1MCdbMM_                  .M@MSN;dM-                       .:
#       )                       .M#(#?d#(Mb.. ...............JMIMIMLdM]                       .:
#       )                      ..M#?NHM# ?MMMMMMMMMH"""""""HMM@(Nad#(Mb                       .:
#       )                  .(MMMMH=..-(Jg[   `               daggmp  MNm,                     .:
#       )                ..MMY`     !qN;                       (J     ?MMN,                   .:
#       )               (MMD`       .MM@                      .MM{      .WMN,                 .:
#       )              dM@`         dMM%                      .MM}        (MMm                .:
#       )             .M#`          dMN!                      .MM}        ~(MMr               .:
#       )            .MM:           dM#                       .MM}        ..JM#               .:
#       )      ``    .M@            dMF                       .MM}        .~(M#   `  .        .:
#       )      ?MMMMMMMNgJ,         .7`                        T"!       .JJjMNgNNMMMB^       .:
#       )            dMr ?Mm,                                            7YYMM#!`             .:
#       )            dMb   ?`                  .,   ` ..                 ~.(MM%               .:
#       )         ..JgMMNNN)                  .Mn.(Mm-JM{               dHHMMNag.,            .:
#       )         ("!  ?MN,..,                (NM@"`~OMM}             ..~-(M@` _?"M[          .:
#       )               ,MMM#_                .M#    .M#`           .~.~JMMMNg-..             .:
#       )           ..gMB"?TMMNJ..              `     _`         .~~.(JdM#^  _"TMMNgJ-,       .:
#       )        .gMB=`      _7WMMNaJ...                 ....__-(JJgMMMM^          ?T"^       .:
#       )           ............  ?TWMMMMNNNNgggggggggggggNNMMMMMMBY7`...                     .:
#       )           WMMMMMMMMMMMMMNgJ,   (dMMMM#"TYYYYYYMMMMMMMNgMMMMMMMMMMMNNgJ-,            .:
#       )            -?TMNmuuuuUWMMMMMMNNMM@g@MMmJ--_(JMMg@g@@gMMMMMMWUXXXUWMMMMMMNe.         .:

def push(k,v):
    if k in dic:
        dic[k] = min(dic[k],v)
    else:
        dic[k] = v
n,x,y = map(int,str(input()).split(' '))
dic = {}
for i in range(0,n):
    a = list(map(int,str(input()).split(' ')))
    k,v =a[0]*y-a[1]*x,a[2]
    l = []
    for j in dic:
        l.append([j,dic[j]])
    for jj in l:
        push(jj[0]+k,jj[1]+v)
    push(k,v)
if 0 in dic:
    print(dic[0])
else:
    print('-1')