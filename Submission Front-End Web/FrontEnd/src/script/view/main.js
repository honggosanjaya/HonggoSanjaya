// API_KEY = '16a6eab45e4dd4ed7ebe9e033e7d959e';
const urlGambar = 'https://image.tmdb.org/t/p/w500';
const baseUrl = 'https://api.themoviedb.org/3/search/movie?api_key=16a6eab45e4dd4ed7ebe9e033e7d959e';

const buttonElement = document.querySelector('#search');
const inputElement = document.querySelector('#input');
const cariFilm = document.querySelector('#cariFilm');

const movieSection = movies =>{
    return movies.map((movie) => {
        if (movie.poster_path) {
            return `<img src=${urlGambar + movie.poster_path} data-movie-id=${movie.id}>`;
        }     
    })
    
}

const createMovieContainer = movies =>{
    const movieElement = document.createElement('div');
    movieElement.setAttribute('class','movie');

    const movieTemplate = `${movieSection(movies)}`;

    movieElement.innerHTML = movieTemplate;
    return movieElement;
}

const render = data => {

    cariFilm.innerHTML = '';
    const movies = data.results;
    const movieBlock = createMovieContainer(movies);
    cariFilm.appendChild(movieBlock);
    console.log('Data: ', data);
}

buttonElement.onclick = event => {
    event.preventDefault();
    const value = inputElement.value;
    const newUrl = `${baseUrl}&query=${value}`;

fetch(newUrl,{
        method: "GET"
    })
        .then(response => {
            return response.json();
        })

        .then(render)
        .catch(error => {
            console.log(error);
        });
    console.log('Value: ', value);
}

function onSubmitHandle(event) {
    event.preventDefault();

    const input = document.querySelector('#input').value;
}

const formName = document.querySelector('#formName');
formName.addEventListener("submit", onSubmitHandle);