This is the assignment for Agustín Marsero

## Compiling

To compile:
```
mkdir build
cd build
cmake ..
make
```

And to run:
```
./img-ly-assignment.exe
```


## Remarks

I left my full git history for observability, but i would probably squash the commits into one when the feature is ready. 


For PipelineStage::process_data():
I thought about implementing the Strategy Pattern or using an enum and a switch instead of a class for each.
But in the future requirements might change and inheriting from PipelineStage is the most flexible option.


At first i thought about creating a std::vector<PipelineStage::Action> for the actions, but then
i thought that a PipelineStage might be able to decide on an action dynamically with the live information.
This is also why it is overrideable.
Eg: After unziping a file in a first step, we might find a file called image.jpeg, 
and with that information we could change the next action to be Action::DecodeImage.
