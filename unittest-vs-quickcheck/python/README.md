# Example (Python)

It's always better to setup a virtualenv when developing python, to avoid
conflicts with you host environment.

You need to have Python 2.7, plus pip and virtualenv.

## Setup a virtual environment

    $ virtualenv --no-site-packages env
    $ source ./env/bin/activate

## Build

    $ pip install -r requirements.txt

## Run the tests

    $ py.test example_test.py
