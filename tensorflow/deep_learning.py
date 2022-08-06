# importing the tensorflow package
import tensorflow as tf
from tensorflow import keras
import numpy as np
import datetime
from tensorflow.python.client import device_lib


def get_available_gpus():
    local_device_protos = device_lib.list_local_devices()
    return [x.name for x in local_device_protos if x.device_type == 'GPU']


def use_gpus(): 
    gpus = tf.config.list_physical_devices('GPU')
    if gpus:
      # Create 2 virtual GPUs with 1GB memory each
      try:
        tf.config.set_logical_device_configuration(
            gpus[0],
            [tf.config.LogicalDeviceConfiguration(memory_limit=1024),
             tf.config.LogicalDeviceConfiguration(memory_limit=1024),
             tf.config.LogicalDeviceConfiguration(memory_limit=1024),
             tf.config.LogicalDeviceConfiguration(memory_limit=1024)])
        logical_gpus = tf.config.list_logical_devices('GPU')
        print(len(gpus), "Physical GPU,", len(logical_gpus), "Logical GPUs")
      except RuntimeError as e:
        # Virtual devices must be set before GPUs have been initialized
        print(e)
        
        
def create_classification_model():
    classification_model = keras.models.Sequential([
                           keras.layers.Flatten(input_shape=(28, 28)),
                           keras.layers.Dense(128, activation='relu'),
                           keras.layers.Dense(10, activation='softmax')
                           ])
    
    classification_model.compile(optimizer='adam',
                                 loss='sparse_categorical_crossentropy',
                                 metrics=['accuracy'])
    
    return classification_model
        
        
        
        
#start

get_available_gpus()
use_gpus()
classification_model = create_classification_model()

#data
handwritten_dataset = tf.keras.datasets.mnist  #downloads the mnist dataset and store them in a variable. 
(x_train, y_train), (x_test, y_test) = handwritten_dataset.load_data()   #splits the dataset into train and test data
x_train, x_test = x_train / 255.0, x_test / 255.0   

#tensorboard, logging en model statistieken
#to launch tensorboard: python -m tensorboard.main --logdir=[PATH_TO_LOGDIR]
log_dir = "logs/fit/" + datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
tensorboard_callback = tf.keras.callbacks.TensorBoard(log_dir=log_dir, histogram_freq=1)

#trainen
classification_model.fit(x_train, 
                         y_train, 
                         epochs = 50, 
                         batch_size = 500,
                         callbacks=[tensorboard_callback])

classification_model.evaluate(x_test,  y_test)

#predictions
predictions=classification_model.predict(x_test)
print("predicted value =",np.argmax(predictions[0]))
print("real value =", y_test[0])
