# Testing and verification

One of the important step during the development and also the product release is the testing.

## data

Data consist of:
* Input data: <uid>_input_data
* Expected output data. <uid>_expected_data
* Application is executed and the output is saved as <uid>_output_data.
* Note: <uid>_output_data is not committed to the repo.
* Test is passed, if the "Output data" and "Expected Output data" are matched.
* Test is failed, if the "Output data" and "Expected Output data" are not matched.

## Unit testing

Unit test code/scripts

* Test script specific to the functionality evaluation.
* Unit test focus on the test cases as required by the algorithm. 
* Unit test covers different set of scenarios and use-cases of the algorithm.

## Integration testing

Integration test code/scripts

* The Integration testing script/code to test overall application and its tool-chain. 
* The script/code executes the unit-test also 
* Test communication between the different modules.
