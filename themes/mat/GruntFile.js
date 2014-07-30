module.exports = function(grunt) {
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-contrib-watch');

  grunt.initConfig({
    'compass': {
      dist: {
        options: {
          config: 'config.rb',
          bundleExec: true,
        }
      }
    },
    'watch': {
      scripts: {
        files: ['**/*.scss'],
        tasks: ['compass'],
        options: {
          spawn: false,
        },
      },
      svg: {
        files: ['**/*.svg'],
        tasks: ['svg-sprites'],
        options: {
          spawn: true,
        },
      }
    },
  });

  grunt.registerTask('default', [
    'compass'
  ]);
};
