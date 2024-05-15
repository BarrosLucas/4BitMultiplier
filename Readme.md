# 🎢 Complete Guide to Testing Your Circuits: From Zero to Simulation! 🚀

This guide will take you on an exciting journey, from creating your circuit to analyzing the simulation results! Get ready to master two approaches: Bottom-Up (starting with logic gates) and Top-Down (starting with the hardware description).

## 🧰 Bottom-Up Approach: Building Block by Block 🧱
**Objective:** Create a 4-bit multiplier with an 8-bit output and test it using SpiceOpus.

**Step-by-Step:**

1. 📄 **Generating the VST File:** This file is essential to visualize the schematic of your circuit. Use the commands:

```
$ export MBK_IN_LO=spi
$ export MBK_OUT_LO=spi
$ genlib -v nome_genlib
```

2. 🔍 **Viewing the Schematic:** See how your circuit connects using the command:

```
$ xsch -l nome
```

3. 🗺️ **Creating the Physical Layout:** Arrange the cells of your circuit in physical space with the command:

```
$ alliance-ocp nome nome_posicionado
```

4. 🔄 **Routing the Cells:** Connect the cells of your circuit using Nero:

```
$ nero -p nome_posicionado nome nome_roteado
```

5. ⚙️ **Extracting Spice Parameters:** Obtain the parameters for simulation using Cougar:

```
$ cougar -t -ac nome_ap
```

6. 📄 **Creating the .cir File:** Create the netlist file by importing the .spi file.

7. ⚡️ **Simulating in SpiceOpus:** SSimulate your circuit and generate graphs!

```
$ spiceopus
$ nomeDoCircuito.cir
```

## 🏗️ Top-Down Approach: From General to Details 🗺️
**Objective:** Create a 4-bit multiplier using VHDL and test it with Asimut.

**Step-by-Step:**

1. ⚙️ **Generating the .vbe File:** Generating the .vbe File:

```
$ vasy -a -I vhdl -a mult4
```

2. 💪 **Optimizing with Boom:** Reduce the number of logic gates in your circuit:

```
$ boom -A -d 100 mult4 mult4_boom
```

3. ✅ **Verifying with Proof:** Make sure that the logic of your circuit has not been altered:

```
$ proof -a -d mult4 mult4_boom
```

4. 📄 **Generating the VST:** Create the VST file from the .vbe using Boog:

```
$ boog mult4_boom mult4_boog
```

5. 🚀 **Physically Optimizing with Loon:** Optimize the physical layout of your circuit:

```
$ loon -m 4 mult4_boog mult4_bbl
```

6. ⚙️ **Generating Test Inputs:** Use Alliance-Genpat to create test inputs from the .C file:

```
$ alliance-genpat -v pattern_mult4
```

7. 🔍 **Viewing the Tests:** View the test inputs using XPat:

```
$ xpat -l pat_multi.pat
```

8. 🗺️ **Creating the Physical Layout:** Arrange the cells of your circuit in physical space:

```
$ alliance-ocp mult4_bbl mult4_ocp
```

9. 🔄 **Routing the Cells:** Connect the cells of your circuit using Nero:

```
$ nero -p mult4_ocp mult4_bbl mult4_nero
```

10. 🔄 **Changing the Environment Variable:** Set the environment variable:

```
$ export MBK_OUT_LO=vst
```

11. ⚙️ **Extracting Spice Parameters:** Obtain the parameters for simulation:

```
$ cougar -t -ac mult4_nero mult4_cougar
```

12. 🧪 **Testing with Asimut:** Run exhaustive tests on your circuit:

```
$ asimut mult4_cougar pat_multi pat_mult_result
```


🎉 Congratulations! You have completed the guide and are ready to create and test your own circuits!  🎉