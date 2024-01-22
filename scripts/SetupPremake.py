import platform
import os
import shutil
import requests
import zipfile
import io

def main():
    system = platform.system() # Determine the user's OS
    print("Requesting support for platform", system)

    licenseURL = "https://github.com/premake/premake-core/blob/master/LICENSE.txt" # Where to download the license from
    directory = os.path.abspath("../vendor/premake/bin") # Where to store the downloaded files to
    licensePath = os.path.join(directory, "LICENSE.txt") # The downloaded license's full directory

    # Windows specific code
    if system == "Windows":
        url = "https://github.com/premake/premake-core/releases/download/v5.0.0-beta2/premake-5.0.0-beta2-windows.zip" # Where to download the premake binary from
        
        # Remove the binary direcotry if it already exists
        if os.path.exists(directory):
            print("Binary directory was found already, deleting it")
            shutil.rmtree(directory)
            
        print("Downloading premake")
        
        # Download premake
        response = requests.get(url)
        
        print("Extracting premake")
        
        # Extract premake
        with zipfile.ZipFile(io.BytesIO(response.content)) as zipFile:
            zipFile.extractall(directory)
            
        print("Removing all non-executable files")
        
        # Remove all non-premake files
        fileNameToKeep = "premake5.exe"
        
        for filename in os.listdir(directory):
            filePath = os.path.join(directory, filename)
            
            if filename != fileNameToKeep:
                os.remove(filePath)
    # All other OS's
    else:            
        print("Unsupported platform!")
        return
    
    print("Downloading license")
    
    # Download the license
    response = requests.get(licenseURL)
    
    # Write the license's content to a file
    with open(licensePath, "wb") as f:
        f.write(response.content)
    
if __name__ == "__main__":
    main()