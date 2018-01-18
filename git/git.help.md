# Syncing to a fork
Sync a fork of a repository to keep it up-to-date with the upstream repository.

> upstream repository: the repo of owner.
> origin repository: the repo which you self own.

## Before syncing: configuring a remote for a fork
- list the current remote repository:
> git remote -v

- Specify a new remote upstream repo:
> git remote add upstream https://github.com/ORIGINAL\_OWNER/ORIGINAL\_REPOSITORY.git

## git fetch upstream

# Configure the Git Server
## Host
### Make sure that there exits (host) id\_rsa file
If it does not, run in shell
```{shell}
ssh-keygen -t rsa -C "youremali@xxx.xx"
# Accept any default option 
```
Then, you will find two file:
- id\_rsa: private key
- id\_rsa.pub: public key

Next, append the content in id\_rsa.pub into the *authorized\_keys* file.

### Push
- git push -u origin mater : For the first time
- git push: For second time : For the second time

## Remote
### Creat git user
```{shell}
sudo git adduser git
```
### Create key
Same with *Host*'s configuration, expect that you have to create */home/git/.ssh/authorized\_keys* file.

### Deny any ssh-login
**sudo vi /etc/passwd**
Change
```
git:x:1001:1001:,,,:/home/git:/bin/bash
```
to
```
git:x:1001:1001:,,,:/home/git:/bin/bash
```
## Init a project
Create a git in remote server.
>cd /srv/

>sudo git init --bare sample.git

>sudo chown -R git:git sample.git

# Keeping a fork up to date
## 1. Clone your fork:

>    git clone git@github.com:YOUR-USERNAME/YOUR-FORKED-REPO.git



## 2. Add remote from original repository in your forked repository: 

>    cd into/cloned/fork-repo
>    git remote add upstream git@github.com:lennylxx/ipv6-hosts.git
>    git fetch upstream


## 3. Updating your fork from original repo to keep up with their changes:

>    git pull upstream master


# ['Merge' specific files from Git branches](https://stackoverflow.com/questions/18115411/how-to-merge-specific-files-from-git-branches)
```
$ git branch
master
*branch1
branch2
```
Aussming you want to merge *file.cpp* in branch2 to *file.cpp* in branch1 (in current branch).
```
#$git checkout branch1
$ git checkout --patch branch2 file.cpp
```
To have full control do an interactive merge using *--patch* switch:
```
y - stage this hunk
n - do not stage this hunk
q - quit; do not stage this hunk nor any of the remaining ones
a - stage this hunk and all later hunks in the file
d - do not stage this hunk nor any of the later hunks in the file
g - select a hunk to go to
/ - search for a hunk matching the given regex
j - leave this hunk undecided, see next undecided hunk
J - leave this hunk undecided, see next hunk
k - leave this hunk undecided, see previous undecided hunk
K - leave this hunk undecided, see previous hunk
s - split the current hunk into smaller hunks
e - manually edit the current hunk
? - print help
```
