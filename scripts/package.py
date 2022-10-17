import sys, os, subprocess
import itertools, shutil 
from typing import Any, Callable, List, Iterable

assignment_path = "../assignments/"
bin_path = "../bin/"

def main():
    assignments = []
    assignments = get_assignment_targets(sys.argv)
    package_dirs = copy_to(assignments)
    package(package_dirs)

def get_assignment_targets(targets: List[str]) -> List[str]:
    assignment_targets = []
    existing_assignments = list(filter(lambda f: "PA" in f, os.listdir("../assignments/")))
    if len(targets) <= 1:
        raise NoTargets
    for s in targets[1:len(targets)]:
        if assignment_exists(s, existing_assignments):
            assignment_targets.append(list(filter((lambda f: ("PA" + s) in f), existing_assignments))[0]) 
        else: 
            raise TargetNotFound
    return assignment_targets

def assignment_exists(a: str, existing: List[str]) -> Any:
    for f in existing:
        if str("PA" + a) in f:
            return True
    return False

def copy_to(files: List[str]) -> List[str]:
    package_dirs = []
    for f in files:
        shutil.copytree(assignment_path + f, bin_path + f + "/" + f, dirs_exist_ok=True)
        shutil.copytree(assignment_path + "vendor", bin_path + f + "/" + "vendor", dirs_exist_ok=True)
        package_dirs.append(bin_path + f)
    return package_dirs

def package(dirs: List[str]) -> None:
    os.chdir(bin_path)
    for d in dirs:
        shutil.make_archive(os.path.basename(d), "zip", d)
        shutil.rmtree(os.path.basename(d))

class NoTargets(Exception):
    def __str__(self):
        return "No Targets!"

class TargetNotFound(Exception):
    def __str__(self):
        return "Target Not Found!"
        
if __name__=='__main__':
    try:
        main(), exit(0)
    except Exception as inst:
        print(type(inst), inst), exit(1)