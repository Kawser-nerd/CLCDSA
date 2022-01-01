import keras.models
import tensorflow as tf
import os
import pandas as pd
from keras.models import Model
from tensorflow.keras.optimizers import SGD
from keras.layers import Dense, Dropout, Input, concatenate, Activation
from keras import backend as K
from keras.utils.generic_utils import get_custom_objects
from customize import SingleConnected
import numpy as np

positivedatasetpath = os.path.join(os.getcwd(), 'PositiveClones.csv')
negativedatasetpath = os.path.join(os.getcwd(), 'NegativeClones1.csv')

dataset = pd.read_csv(positivedatasetpath, delimiter=',')
dataset = dataset.append(pd.read_csv(negativedatasetpath, delimiter=','))
dataset = dataset.to_numpy()
shape = 9  ## dataset dividation


class DNNModel:
    def __init__(self):
        # CPU enable for
        os.environ["CUDA_DEVICE_ORDER"] = "PCI_BUS_ID"  # see issue #152
        os.environ["CUDA_VISIBLE_DEVICES"] = '-1'

        # GPU enabled for
        #sess = tf.compat.v1.Session(config=tf.compat.v1.ConfigProto(log_device_placement=True))
        #K.clear_session()
        #K.set_session(sess)
        self.dataset = dataset
        get_custom_objects().update({'activation': Activation(self.custom_activation)})

    @tf.keras.utils.register_keras_serializable()
    def custom_activation(self, x):
        return 1 / (1 + tf.exp(-tf.reduce_sum(x, axis=-1, keepdims=True)))

    def dlModel(self):

        # first initialization layer
        model1_Input = Input(shape=(shape,))
        model1_hidden1 = Dense(100, activation='relu', kernel_initializer='he_normal')(model1_Input)
        model1_dropout1 = Dropout(0.2)(model1_hidden1)
        model1_hidden2 = Dense(100, activation='relu', kernel_initializer='he_normal')(model1_dropout1)
        model1_dropout2 = Dropout(0.2)(model1_hidden2)
        model1_hidden3 = Dense(100, activation='relu', kernel_initializer='he_normal')(model1_dropout2)
        model1_dropout3 = Dropout(0.2)(model1_hidden3)
        model1_hidden4 = Dense(100, activation='relu', kernel_initializer='he_normal')(model1_dropout3)
        model1_dropout4 = Dropout(0.2)(model1_hidden4)
        model1_hidden5 = Dense(100, activation='relu', kernel_initializer='he_normal')(model1_dropout4)
        model1_output = Dropout(0.2)(model1_hidden5)


        # second Initialization layer
        model2_Input = Input(shape=(shape,))
        model2_hidden1 = Dense(100, activation='relu', kernel_initializer='he_normal')(model2_Input)
        model2_dropout1 = Dropout(0.2)(model2_hidden1)
        model2_hidden2 = Dense(100, activation='relu', kernel_initializer='he_normal')(model2_dropout1)
        model2_dropout2 = Dropout(0.2)(model2_hidden2)
        model2_hidden3 = Dense(100, activation='relu', kernel_initializer='he_normal')(model2_dropout2)
        model2_dropout3 = Dropout(0.2)(model2_hidden3)
        model2_hidden4 = Dense(100, activation='relu', kernel_initializer='he_normal')(model2_dropout3)
        model2_dropout4 = Dropout(0.2)(model2_hidden4)
        model2_hidden5 = Dense(100, activation='relu', kernel_initializer='he_normal')(model2_dropout4)
        model2_output = Dropout(0.2)(model2_hidden5)

        # Comparator model
        merged_model = concatenate([model1_output, model2_output])
        comparator_layer1 = Dense(100, activation='relu', kernel_initializer='he_normal')(merged_model)
        comparator_layer1_Dropout = Dropout(0.2)(comparator_layer1)
        comparator_layer2 = Dense(75, activation='relu', kernel_initializer='he_normal')(comparator_layer1_Dropout)
        comparator_layer2_Dropout = Dropout(0.2)(comparator_layer2)
        comparator_layer3 = Dense(50, activation='relu', kernel_initializer='he_normal')(comparator_layer2_Dropout)
        comparator_layer3_Dropout = Dropout(0.2)(comparator_layer3)
        comparator_layer4 = Dense(25, activation='relu', kernel_initializer='he_normal')(comparator_layer3_Dropout)
        comparator_layer4_Dropout = Dropout(0.2)(comparator_layer4)
        comparator_layer5 = Dense(10, activation='relu', kernel_initializer='he_normal')(comparator_layer4_Dropout)
        comparator_layer5_Dropout = Dropout(0.2)(comparator_layer5)
        compilation_layer = SingleConnected()(comparator_layer5_Dropout)
        final_output = Dense(1, activation='activation')(compilation_layer)

        model = Model(inputs=[model1_Input, model2_Input], outputs=final_output)
        return model

    def mainModel(self, X1, X2, y, save=0):
        model = self.dlModel()
        optimizer = SGD(learning_rate=0.0001, decay=0.03)
        model.compile(loss='binary_crossentropy', optimizer=optimizer, metrics=['accuracy'])
        model.fit([X1, X2], y, epochs=10, batch_size=500)
        _, accuracy = model.evaluate([X1, X2], y)
        print('Accuracy: %.2f' % (accuracy * 100))
        if(save):
            model.save("model.h5")
            model.save("CLCDSA_Model")
            print("Model Saved to disk")

        predictions = (model([X1, X2]) > 0.5).astype(int)
        for i in range(10):
            print('%s %s => %d (expected %d))' % (X1[i].tolist(), X2[i].tolist(), predictions[i], y[i]))


    def testMOdel(self, X1, X2, y):
        model = keras.models.load_model('CLCDSA_Model')

        predictions = (model([X1, X2]) > 0.5)
        predictions = np.array(predictions)

        for i in range(10000,10010):
            print('%s %s => %d (expected %d))' % (X1[i].tolist(), X2[i].tolist(), predictions[i], y[i]))

# make class predictions with the model

if __name__ == "__main__":

    x = DNNModel()
    X1 = dataset[:, 0:shape]
    X2 = dataset[:, shape:18]
    y = dataset[:, 18]
    x.mainModel(X1, X2, y, save=0)
    x.testMOdel(X1, X2, y)

