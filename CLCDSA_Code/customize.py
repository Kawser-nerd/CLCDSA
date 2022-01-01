
from keras.engine.base_layer import Layer
import tensorflow as tf

@tf.keras.utils.register_keras_serializable()
class SingleConnected(Layer):

    #creator
    def __init__(self, **kwargs):
        super(SingleConnected, self).__init__(**kwargs)

        # creates weights

    def build(self, input_shape):
        input_shape = tf.TensorShape(input_shape)
        weight_shape =tf.compat.dimension_value(input_shape[-1])

        self.kernel = self.add_weight(name='kernel',
                                      shape=[weight_shape],
                                      initializer='he_normal',
                                      trainable=True)

        self.bias = self.add_weight(name='bias',
                                    shape=weight_shape,
                                    initializer='zeros',
                                    trainable=True)

        self.built = True

        # operation:

    def call(self, inputs):
        return (inputs * self.kernel + self.bias)

        # output shape

    def compute_output_shape(self, input_shape):
        return input_shape

        # for saving the model - only necessary if you have parameters in __init__

    def get_config(self):
        config = super(SingleConnected, self).get_config()
        return config