# IA repository

My first tries with Artificial Intelligence.

I'm actually using the FANN library to emulate Neural Networks.

Observations :

- The "intelligence" of a trained ANN (Artificial Neural Network) highly depends on the number of hidden neurons layers and their number of neurons. And more isn't necessarily better.
For a simple problem (a NOT) (with input 1, expected is 0, with input 0, expect is 1), a uniq layer with a uniq neuron is sufficient to get a very nice result (no errors on 200k tests), with 37 Epochs of training.
But with 50 layers of 5 neurons each, the ANN has still an error rate of 25% after 2000 Epochs of training.
Maybe with a lot more training, this configuration will work, but we can do it simply with only 1 neuron, so ... ;)

<h2> 1-2-2-1 configuration seems more efficient than 1-4-1 ... </h2>

What's the reason of that ? Let's try to figure it out.


- How many "synapse" can we have on the first config ?

first

	first[0]->second[0]
	first[0]->second[1]

then

	second[0]->third[0]
	second[0]->third[1]
	second[1]->third[0]
	second[1]->third[1]

final

	third[0]->first[0]
	third[1]->first[0]

So we get a total amount of <b>2 + 4 + 2 = 8 synapses</b>. (and so 8 different weights possibilities).

- What about the second configuration ?

first

	first[0]->second[0]
	first[0]->second[1]
	first[0]->second[2]
	first[0]->second[3]

final

	second[0]->third[0]
	second[1]->third[0]
	second[2]->third[0]
	second[3]->third[0]

So we get a total of <b>4 + 4 = 8 synapses</b>. (still 8 different weights possibilities).

The numbers of activation functions is still the same in both : 4.

<h3>How can we get a significative difference of capability ?</h3>

Good question.
