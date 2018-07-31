# coding: utf-8

from flask import Flask
app = Flask(__name__)


@app.route('/projects/')
def projects():
    return 'The project page'


@app.route('/about/<user_name>')
def about(user_name):
    return 'The about page %s' % user_name


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=9850, debug=True)