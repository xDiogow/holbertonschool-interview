#!/usr/bin/node

const request = require('request');

if (process.argv.length < 3) {
  console.log('Usage: ./0-starwars_characters.js <Movie_ID>');
  process.exit(1);
}

const movieId = process.argv[2];
const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

request(apiUrl, function (error, response, body) {
  if (error) {
    console.error(error);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  // Helper function to print characters in order
  const printCharacters = (index) => {
    if (index >= characters.length) return;

    request(characters[index], function (err, res, data) {
      if (err) {
        console.error(err);
        return;
      }

      const character = JSON.parse(data);
      console.log(character.name);
      printCharacters(index + 1);
    });
  };

  printCharacters(0);
});

