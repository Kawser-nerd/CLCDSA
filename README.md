# CLCDSA
CLCDSA: Cross Language Code Clone Detection using Syntactical Features and API Documentation

The trained model in saved both as .h5 and the weight model format under CLCDSA_DLCC. A to test it one needs to configure the data first and then need to load the model. We collected the features for source code using antlr v4 (Grammars and source codes are provided). For our case, we got training accuracy around 73% with the datasource we provided. And it is always best to train the model with CPU.

A partial test results are given below:

[2, 0, 0, 0, 0, 2, 0, 0, 0] [2, 1, 0, 0, 0, 3, 0, 0, 1] => 1 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [2, 1, 0, 0, 0, 3, 0, 0, 1] => 1 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [3, 1, 1, 1, 0, 1, 0, 0, 1] => 1 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [1, 1, 1, 1, 0, 1, 0, 0, 1] => 1 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [0, 1, 1, 1, 0, 1, 0, 0, 1] => 0 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [2, 1, 0, 0, 0, 3, 0, 0, 1] => 1 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [2, 1, 0, 0, 0, 1, 0, 0, 1] => 1 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [4, 0, 0, 0, 0, 0, 0, 0, 3] => 1 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [2, 1, 0, 0, 0, 3, 0, 0, 1] => 0 (expected 1))
[2, 0, 0, 0, 0, 2, 0, 0, 0] [1, 1, 4, 4, 0, 2, 0, 0, 1] => 1 (expected 1))
[11, 5, 88, 88, 4, 40, 0, 2, 37] [3, 0, 2, 2, 1, 1, 0, 0, 2] => 0 (expected 0))
[224, 170, 568, 568, 112, 527, 6, 2, 465] [11, 0, 19, 19, 4, 19, 0, 0, 12] => 0 (expected 0))
[10, 1, 19, 19, 3, 11, 0, 0, 24] [1, 0, 2, 2, 0, 1, 0, 0, 2] => 0 (expected 0))
[23, 4, 41, 41, 7, 34, 0, 0, 21] [26, 50, 40, 40, 1, 42, 0, 0, 33] => 0 (expected 0))
[167, 129, 440, 440, 73, 375, 0, 2, 320] [5, 1, 0, 0, 0, 1, 0, 0, 1] => 0 (expected 0))
[13, 1, 13, 13, 2, 7, 0, 0, 5] [15, 2, 20, 20, 3, 12, 0, 0, 6] => 0 (expected 0))
[16, 2, 37, 37, 3, 33, 2, 1, 43] [8, 0, 10, 10, 2, 7, 0, 0, 8] => 0 (expected 0))
[3, 1, 5, 5, 0, 4, 0, 0, 1] [18, 1, 24, 24, 5, 24, 0, 0, 9] => 0 (expected 0))
[7, 1, 9, 9, 2, 5, 0, 0, 9] [15, 3, 30, 30, 6, 22, 0, 0, 13] => 0 (expected 0))
[4, 1, 3, 3, 1, 5, 0, 0, 3] [6, 1, 7, 7, 2, 2, 0, 0, 6] => 1 (expected 0))
[3, 1, 7, 7, 0, 4, 0, 0, 3] [26, 10, 46, 46, 8, 53, 0, 0, 23] => 1 (expected 0))
[13, 1, 11, 11, 1, 7, 0, 0, 3] [8, 1, 4, 4, 3, 5, 0, 0, 6] => 0 (expected 0))
