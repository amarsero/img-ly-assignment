# IMG.LY Assignment

This is the assignment for Agustín Marsero.
It took me 4 hours.

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

I left my full git history for observability, but I would probably squash the commits into one when the feature is ready. 


### For PipelineStage::process_data():
I thought about implementing the Strategy Pattern or using an enum and a switch instead of a class for each.
However, since future requirements might change, inheriting from `PipelineStage` offers greater flexibility.

### Selecting the action
At first I thought about creating a `std::vector<PipelineStage::Action>` for the actions, but then
I thought that a PipelineStage might be able to decide on an action dynamically with the live information.
This is why the `get_next_action()` method is overrideable.
For example: After unzipping a file in a first step, we might find a file called image.jpeg, 
and with that information we could change the next action to be `Action::DecodeImage`.
