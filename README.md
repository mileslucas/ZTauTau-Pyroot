# ZTauTau-Pyroot

This repository is a source for the data and demo files for the Iowa State University Physics 322 lab that seeks to find the cross-section of the Z boson to tau-tau lepton reaction. The code for this is presented in jupyter notebooks using rootpy.

# Prerequisites

If anybody wishes to use this code on their personal machines there are a number of prerequisites. The three main components are

Python
Root
rootpy

I highly recommend the following steps for installation to ensure a working environment for this code. Also, I will be assuming use of a unix-based operating system. Note: Root6 does not support Windows installations.

### Python
I recommend using the Anaconda package manager, although python in conjunction with pip is enough. The advantage of using Anaconda is the inclusiveness of the SciPy stack and a built in, ipython enabled editor. To get Anaconda, follow the instructions on https://www.continuum.io/downloads and make sure to download the python 3.6 flavor.

### Root
Root is a pain in the butt to install! First off, make sure your python is already downloaded and installed (which should happen automatically with anaconda). To test if python is installed, open a command line and type $python --version$ If you get a command not found error, see the above steps for installing python. To get the most recent root production code, see the page https://root.cern.ch/content/release-60806. However, I recommend checking out or downloading the repository at http://root.cern.ch/git/root.git.

Once root is downloaded we have to build it. Cern provides instructions here https://root.cern.ch/building-root. Before we continue, make sure you have all the prerequisites installed https://root.cern.ch/build-prerequisites. There is an inclusive install command listing below each family. Create a folder anywhere on your system (I recommend the home folder, ~/). You can name it anything but calling it "root" is acceptable. Navigate into this folder. From here call
cmake path-to-root-download
Then call
cmake --build . --
This will take a while. Once you're finished, test the installation by executing the following
. path-to-install/bin/thisroot.sh
root
if you get into the prompt, good work. To exit, type .q

### rootpy
