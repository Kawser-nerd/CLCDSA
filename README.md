# CLCDSA
CLCDSA: Cross Language Code Clone Detection using Syntactical Features and API Documentation

The trained model in saved both as .h5 and the weight model format under CLCDSA_DLCC. A to test it one needs to configure the data first and then need to load the model. We collected the features for source code using antlr v4 (Grammars and source codes are provided). For our case, we got training accuracy around 73% with the datasource we provided. And it is always best to train the model with CPU.
