# IA repository

My first tries with Artificial Intelligence.

I'm actually using the FANN library to emulate Neural Networks.

Observations :

- The "intelligence" of a trained ANN (Artificial Neural Network) highly depends on the number of hidden neurons layers and their number of neurons. And more isn't necessarily better.
For a simple problem (a NOT) (with input 1, expected is 0, with input 0, expect is 1), a uniq layer with a uniq neuron is sufficient to get a very nice result (no errors on 200k tests), with 37 Epochs of training.
But with 50 layers of 5 neurons each, the ANN has still an error rate of 25% after 2000 Epochs of training.
Maybe with a lot more training, this configuration will work, but we can do it simply with only 1 neuron, so ... ;)