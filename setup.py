from setuptools import setup
import os
import glob


package_name = 'my_package'
share_dir = 'share/' + package_name

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (share_dir + '/launch', glob.glob(os.path.join('launch', '*.launch.py'))),
        (share_dir + '/param', glob.glob(os.path.join('param', '*.yaml'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='aa',
    maintainer_email='freshmea@naver.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'mp = my_package.mpub:main',
            'ms = my_package.msub:main',
            'mtp = my_package.mtpub:main',
            'ts = my_package.tsub:main',
            'moveturtle = my_package.move_turtle:main',
            'moveturtle2 = my_package.move_turtle2:main',
            'moveturtle3 = my_package.move_turtle3:main',
            'movearm = my_package.move_arm:main'
        ],
    },
)
