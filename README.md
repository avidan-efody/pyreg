# about
This repo shows how to call a python function from SV, then have this function kick off SV tasks and wait for them to return. This is often useful if you have a long firmware sequence that is coded in python and you want to run it from SV code. The python firmware sequence will send individual reads/writes to SV for execution.

# prerequisites
cmake of a reasonably recent version

# running instructions

```
git clone https://github.com/avidan-efody/pyreg.git

cd pyreg/run_here/
vi runme # enable your simulator
source runme
```
